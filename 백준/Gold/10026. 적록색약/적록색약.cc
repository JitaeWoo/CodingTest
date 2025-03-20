#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::string;

void f1(char painting[][100], int check[][100], char color, int x, int y, int N){
	if(x > 0 && check[x-1][y] != 1 && painting[x-1][y] == color){
		check[x-1][y] = 1;
		f1(painting, check, color, x-1, y, N);
	}
	if(x < N-1 && check[x+1][y] != 1 && painting[x+1][y] == color){
		check[x+1][y] = 1;
		f1(painting, check, color, x+1, y, N);
	}
	if(y > 0 && check[x][y-1] != 1 && painting[x][y-1] == color){
		check[x][y-1] = 1;
		f1(painting, check, color, x, y-1, N);
	}
	if(y < N-1 && check[x][y+1] != 1 && painting[x][y+1] == color){
		check[x][y+1] = 1;
		f1(painting, check, color, x, y+1, N);
	}
}

void f2(char painting[][100], int check[][100], char color, int x, int y, int N){
	bool isBlue = false;
	if(color == 'B'){
		isBlue = true;
	}
	if(x > 0 && check[x-1][y] != 1 && (painting[x-1][y] == 'B') == isBlue){
		check[x-1][y] = 1;
		f2(painting, check, color, x-1, y, N);
	}
	if(x < N-1 && check[x+1][y] != 1 && (painting[x+1][y] == 'B') == isBlue){
		check[x+1][y] = 1;
		f2(painting, check, color, x+1, y, N);
	}
	if(y > 0 && check[x][y-1] != 1 && (painting[x][y-1] == 'B') == isBlue){
		check[x][y-1] = 1;
		f2(painting, check, color, x, y-1, N);
	}
	if(y < N-1 && check[x][y+1] != 1 && (painting[x][y+1] == 'B') == isBlue){
		check[x][y+1] = 1;
		f2(painting, check, color, x, y+1, N);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	string str = "";
	char painting[100][100] = {};
	for(int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			painting[i][j] = str[j];
		}
	}
	
	int check[100][100]={};
	int result = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(check[i][j] == 0){
				check[i][j] = 1;
				f1(painting, check, painting[i][j], i, j,  N);
				result++;
			}
		}
	}
	cout << result << " ";
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			check[i][j] = 0;
		}
	}
	result = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(check[i][j] == 0){
				check[i][j] = 1;
				f2(painting, check, painting[i][j], i, j, N);
				result++;
			}
		}
	}
	cout << result << "\n";
	
	return 0;
}