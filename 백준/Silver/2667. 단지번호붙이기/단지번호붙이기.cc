#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::sort;
using std::string;

int house(char map[][25], int x, int y){
	if(x < 0 || x > 24 || y < 0 || y > 24){
		return 0;
	}
	
	int sum = 0;
	if(map[x][y] == '1'){
		map[x][y] = '0';
		sum++;
		sum += house(map, x+1, y);
		sum += house(map, x-1, y);
		sum += house(map, x, y+1);
		sum += house(map, x, y-1);
	}
	
	return sum;
}

int main(void){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	char map[25][25];
	string str = "";
	for(int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			map[i][j] = str[j];
		}
	}
	
	int result[25*25]={};
	int idx = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == '1'){
				result[idx++] = house(map, i, j);
			}
		}
	}
	
	sort(result, result+idx);
	
	cout << idx << "\n";
	for(int i = 0; i < idx; i++){
		cout << result[i] << "\n";
	}
	
	return 0;
}