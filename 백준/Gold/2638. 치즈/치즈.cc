#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::pair;
using std::make_pair;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int cheese[N][M]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> cheese[i][j];
		}
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int x = 0, y = 0, hours = 0;
	queue<pair<int, int>> q;
	bool isCheese = false;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(cheese[i][j] == 1){
				isCheese = true;
				break;
			}
		}
		if(isCheese){
			break;
		}
	}
	while(isCheese){
		hours++;
		q.push(make_pair(0, 0));
		cheese[0][0] = 7;
		while(!q.empty()){ // 치즈 외부 공기를 7로 구분
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for(int i = 0; i < 4; i++){
				int tx = x + dx[i];
				int ty = y + dy[i];
				if(tx < 0 || tx >= M || ty < 0 || ty >= N){
					continue;
				}
				if(cheese[ty][tx] != 7 && cheese[ty][tx] != 1){
					cheese[ty][tx] = 7;
					q.push(make_pair(tx, ty));
				}
			}
		}
		
		for(int i = 0; i < N; i++){ // 외부에 2칸이상 노출된 치즈 삭제
			for(int j = 0; j < M; j++){
				if(cheese[i][j] == 1){
					int Air = 0;
					for(int k = 0; k < 4; k++){
						int tx = j + dx[k];
						int ty = i + dy[k];
						if(tx < 0 || tx >= M || ty < 0 || ty >= N){
							continue;
						}
						if(cheese[ty][tx] == 7){
							Air++;
						}
					}
					if(Air >= 2){
						cheese[i][j] = 0;
					}
				}
			}
		}
		
		isCheese = false;
		for(int i = 0; i < N; i++){ // 외부 공기 초기화 및 치즈 있는지 확인
			for(int j = 0; j < M; j++){
				if(cheese[i][j] == 7){
					cheese[i][j] = 0;
				}
				if(cheese[i][j] == 1){
					isCheese = true;
				}
			}
		}
	}
	
	cout << hours << "\n";
	
	
	return 0;
}