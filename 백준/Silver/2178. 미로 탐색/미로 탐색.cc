#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	char maze[N][M]={};
	string str="";
	for(int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < M; j++){
			maze[i][j] = str[j];
		}
	}
	
	queue<int> q;
	q.push(-1);
	int result = 1, x = 0, y = 0;
	maze[0][0] = '0';
	while(true){
		if(y == N-1 && x == M-1){
			break;
		}
		if(y > 0 && maze[y-1][x] != '0'){ // 위로 올라감
			maze[y-1][x] = '0';
			q.push(x);
			q.push(y-1);
		}
		if(y < N-1 && maze[y+1][x] != '0'){ // 아래로 내려감
			maze[y+1][x] = '0';
			q.push(x);
			q.push(y+1);
		}
		if(x > 0 && maze[y][x-1] != '0'){ // 왼쪽으로 감
			maze[y][x-1] = '0';
			q.push(x-1);
			q.push(y);
		}
		if(x < M-1 && maze[y][x+1] != '0'){ // 오른쪽으로 감
			maze[y][x+1] = '0';
			q.push(x+1);
			q.push(y);
		}
		
		if(q.front() == -1){
			q.pop();
			result++;
			q.push(-1);
		}
		x = q.front(); q.pop();
		y = q.front(); q.pop();
	}
	
	cout << result << "\n";
	
	return 0;
}