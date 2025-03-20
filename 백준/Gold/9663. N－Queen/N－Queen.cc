#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::ios;
using std::abs;

void Queen(int col[], int x, int N, int* result){
	if(x == N){
		(*result)++;
	}else{
		for(int i = 0; i < N; i++){
			col[x] = i;
			bool isQueen = false;
			for(int j = 0; j < x; j++){
				if(col[j] == col[x] || abs(col[x] - col[j]) == x - j){ // 대각선이나 같은 행에 있으면
					isQueen = true;
				}
			}
			if(!isQueen){ // 퀸이 없는 곳이라면 두고 다음 열로 이동
				Queen(col, x+1, N, result);
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int col[N]={};
	int result = 0;
	Queen(col, 0, N, &result);
	
	cout << result << "\n";
	
	
	return 0;
}