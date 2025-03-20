#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int map[N][M]={};
	int x = 0, y = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if(map[i][j] == 2){
				y = i;
				x = j;
			}
		}
	}
	
	queue<int> q;
	int distanceMap[N][M]={};
	distanceMap[y][x] = 0;
	int distance = 1;
	q.push(-1);
	while(true){
		if(x > 0 && map[y][x-1] == 1){
			map[y][x-1] = 0;
			distanceMap[y][x-1] = distance;
			q.push(y);
			q.push(x-1);
		}
		if(x < M-1 && map[y][x+1] == 1){
			map[y][x+1] = 0;
			distanceMap[y][x+1] = distance;
			q.push(y);
			q.push(x+1);
		}
		if(y > 0 && map[y-1][x] == 1){
			map[y-1][x] = 0;
			distanceMap[y-1][x] = distance;
			q.push(y-1);
			q.push(x);
		}
		if(y < N-1 && map[y+1][x] == 1){
			map[y+1][x] = 0;
			distanceMap[y+1][x] = distance;
			q.push(y+1);
			q.push(x);
		}
		
		if(q.front() == -1){
			q.pop();
			if(q.empty()){
				break;
			}else{
				q.push(-1);
				distance++;
			}
		}
		
		y = q.front(); q.pop();
		x = q.front(); q.pop();
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 1){
				distanceMap[i][j] = -1;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << distanceMap[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}