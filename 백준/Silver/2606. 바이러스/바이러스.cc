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
	
	int graph[N+1][N+1]={};
	int exploredNode[N+1]={};
	queue<int> q;
	int a = 0, b = 0;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	int node = 1, result = 0;
	exploredNode[1] = 1;
	while(true){
		for(int i = 1; i <= N; i++){
			if(graph[node][i] == 1 && exploredNode[i] == 0){ // 연결되어 있고 탐색한 적이 없다면
				q.push(i);
				exploredNode[i] = 1;
				result++;
			}
		}
		if(q.empty()){
			break;
		}else{
			node = q.front();
			q.pop();
		}
	}
	
	cout << result << "\n";
	
	
	
	return 0;
}