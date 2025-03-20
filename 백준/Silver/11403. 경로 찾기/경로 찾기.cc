#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int graph[N][N]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> graph[i][j];
		}
	}
	
	int node = 0;
	int result[N][N]={};
	queue<int> q;
	for(int i = 0; i < N; i++){
		node = i;
		while(true){
			for(int j = 0; j < N; j++){
				if(graph[node][j] == 1 && result[i][j] != 1){
					result[i][j] = 1;
					q.push(j);
				}
			}
			
			if(q.empty()){
				break;
			}else{
				node = q.front(); q.pop();
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}