#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M = 0, N = 0, H = 0;
	cin >> M >> N >> H;
	
	int box[H][N][M]={};
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				cin >> box[i][j][k];
			}
		}
	}
	
	queue<int> q;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(box[i][j][k] == 1){
					q.push(i);
					q.push(j);
					q.push(k);
				}
			}
		}
	}
	if(q.empty()){
		cout << "-1\n";
		return 0;
	}
	q.push(-1);
	
	int x = 0, y = 0, h = 0, level = 0;
	h = q.front(); q.pop();
	y = q.front(); q.pop();
	x = q.front(); q.pop();
	while(true){
		if(x > 0 && box[h][y][x-1] == 0){
			box[h][y][x-1] = 1;
			q.push(h);
			q.push(y);
			q.push(x-1);
		}
		if(x < M-1 && box[h][y][x+1] == 0){
			box[h][y][x+1] = 1;
			q.push(h);
			q.push(y);
			q.push(x+1);
		}
		if(y > 0 && box[h][y-1][x] == 0){
			box[h][y-1][x] = 1;
			q.push(h);
			q.push(y-1);
			q.push(x);
		}
		if(y < N-1 && box[h][y+1][x] == 0){
			box[h][y+1][x] = 1;
			q.push(h);
			q.push(y+1);
			q.push(x);
		}
		if(h > 0 && box[h-1][y][x] == 0){
			box[h-1][y][x] = 1;
			q.push(h-1);
			q.push(y);
			q.push(x);
		}
		if(h < H-1 && box[h+1][y][x] == 0){
			box[h+1][y][x] = 1;
			q.push(h+1);
			q.push(y);
			q.push(x);
		}
		
		
		if(q.front() == -1){
			q.pop();
			if(!q.empty()){
				q.push(-1);
				level++;
			}
		}
		
		if(q.empty()){
			break;
		}else{
			h = q.front(); q.pop();
			y = q.front(); q.pop();
			x = q.front(); q.pop();
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(box[i][j][k] == 0){
					cout << "-1\n";
					return 0;
				}
			}
		}
	}
	
	cout << level << "\n";
	
	return 0;
}