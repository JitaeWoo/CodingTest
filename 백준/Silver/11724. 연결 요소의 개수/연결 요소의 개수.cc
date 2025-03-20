#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

void Connect(int exploredNode[], int i){
	
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int graph[N+1][N+1]={};
	int a = 0, b = 0;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	int exploredNode[N+1]={};
	queue<int> q;
	int node = 0, result = 0;
	for(int i = 1; i <= N; i++){
		if(exploredNode[i] == 0){
			node = i;
			exploredNode[i] == 1;
			result++;
			while(true){
				for(int j = 1; j <= N; j++){
					if(graph[node][j] == 1 && exploredNode[j] == 0){
						exploredNode[j] = 1;
						q.push(j);
					}
				}
				if(q.empty()){
					break;
				}else{
					node = q.front();
					q.pop();
				}
			}
		}
	}
	
	cout << result << "\n";
	
	return 0;
}