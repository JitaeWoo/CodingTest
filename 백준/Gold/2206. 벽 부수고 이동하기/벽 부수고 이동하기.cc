#include <iostream>
#include <string>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::queue;


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	string str = "";
	int map[N][M]={};
	for(int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < M; j++){
			map[i][j] = str[j] - '0';
		}
	}
	
	queue<int> q;
	int check[2][N][M];
	for(int i = 0; i < 2; i ++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				check[i][j][k] = 0;
			}
		}
	}
	check[0][0][0] = 1;
	int n = 0, m = 0, dist = 1, punch = 0, level = 1;
	q.push(-1);
	while(true){
		if(n == N-1 && m == M-1){
			break;
		}
		// 위
		if(n > 0 && check[punch][n-1][m] != 1){
			check[punch][n-1][m] = 1;
			if(map[n-1][m] != 1 || punch == 0){
				q.push(n-1);
				q.push(m);
				if(map[n-1][m] == 1){
					q.push(punch+1);
				}else{
					q.push(punch);
				}
			}
		}
		
		// 아래
		if(n < N-1 && check[punch][n+1][m] != 1){
			check[punch][n+1][m] = 1;
			if(map[n+1][m] != 1 || punch == 0){
				q.push(n+1);
				q.push(m);
				if(map[n+1][m] == 1){
					q.push(punch+1);
				}else{
					q.push(punch);
				}	
			}
		}
		
		// 왼쪽
		if(m > 0 && check[punch][n][m-1] != 1){
			check[punch][n][m-1] = 1;
			if(map[n][m-1] != 1 || punch == 0){
				q.push(n);
				q.push(m-1);
				if(map[n][m-1] == 1){
					q.push(punch+1);
				}else{
					q.push(punch);
				}	
			}
		}
		
		// 오른쪽
		if(m < M-1 && check[punch][n][m+1] != 1){
			check[punch][n][m+1] = 1;
			if(map[n][m+1] != 1 || punch == 0){
				q.push(n);
				q.push(m+1);
				if(map[n][m+1] == 1){
					q.push(punch+1);
				}else{
					q.push(punch);
				}	
			}
		}
		
		if(q.front() == -1){
			level++;
			q.pop();
			if(q.empty()){
				level = -1;
				break;
			}
			q.push(-1);
		}
		
		n = q.front(); q.pop();
		m = q.front(); q.pop();
		punch = q.front(); q.pop();
	}
	
	cout << level << "\n";
	
	return 0;
}