#include <iostream>
using std::cout;
using std::cin;
using std::ios;

void cut(int paper[][128], int* white, int* blue, int N, int x, int y){
	int start = paper[x][y];
	
	for(int i = x; i < x+N; i++){
		for(int j = y; j < y+N; j++){
			if(start != paper[i][j]){
				cut(paper, white, blue, N/2, x, y);
				cut(paper, white, blue, N/2, x+N/2, y);
				cut(paper, white, blue, N/2, x, y+N/2);
				cut(paper, white, blue, N/2, x+N/2, y+N/2);
				return;
			}
		}
	}
	
	if(start == 0){
		(*white)++;
	}else{
		(*blue)++;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int paper[128][128];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> paper[i][j];
		}
	}
	
	int white = 0, blue = 0;
	cut(paper, &white, &blue, N, 0, 0);
	
	cout << white << "\n" << blue << "\n";
	
	return 0;
}