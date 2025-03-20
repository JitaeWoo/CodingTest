#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M = 0, N = 0;
	cin >> M >> N;
	
	int box[N][M]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> box[i][j];
		}
	}
	
	queue<int> q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(box[i][j] == 1){
				q.push(i);
				q.push(j);
			}
		}
	}
	if(q.empty()){
		cout << "-1\n";
		return 0;
	}
	q.push(-1);
	
	int x = 0, y = 0, level = 0;
	y = q.front(); q.pop();
	x = q.front(); q.pop();
	while(true){
		if(x > 0 && box[y][x-1] == 0){
			box[y][x-1] = 1;
			q.push(y);
			q.push(x-1);
		}
		if(x < M-1 && box[y][x+1] == 0){
			box[y][x+1] = 1;
			q.push(y);
			q.push(x+1);
		}
		if(y > 0 && box[y-1][x] == 0){
			box[y-1][x] = 1;
			q.push(y-1);
			q.push(x);
		}
		if(y < N-1 && box[y+1][x] == 0){
			box[y+1][x] = 1;
			q.push(y+1);
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
			y = q.front(); q.pop();
			x = q.front(); q.pop();
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(box[i][j] == 0){
				cout << "-1\n";
				return 0;
			}
		}
	}
	
	cout << level << "\n";
	
	return 0;
}