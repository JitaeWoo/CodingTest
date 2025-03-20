#include <iostream>
using std::cout;
using std::cin;
using std::ios;

void caggage(int field[][50], int x, int y){
	if(x < 0 || x > 49 || y < 0 || y > 49){
		return;
	}
	
	if(field[x][y] == 1){
		field[x][y] = 0;

		caggage(field, x+1, y);
		caggage(field, x, y+1);
		caggage(field, x-1, y);
		caggage(field, x, y-1);	
	}
}
int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int M = 0, N = 0, K = 0 , x = 0, y = 0, num = 0;
	int field[50][50] = {0};
	bool isEmpty = false;
	for(int i = 0; i < T; i++){
		cin >> M >> N >> K;
		num = 0;
		for(int i = 0; i < K; i++){
			cin >> x >> y;
			field[x][y] = 1;
		}
		
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(field[i][j] == 1){
					caggage(field, i, j);
					num++;
				}
			}
		}
		
		cout << num << "\n";
	}
	
	return 0;
}