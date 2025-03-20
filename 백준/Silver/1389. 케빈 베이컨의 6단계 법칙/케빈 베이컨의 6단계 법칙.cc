#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int graph[101][101]={};
	int Node[101]={};
	queue<int> queue;
	int N = 0, M = 0;
	cin >> N >> M;
	
	int a = 0, b = 0;
	for(int i = 0; i < M; i++){ // 그래프 생성
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	int level = 0, min = 5000, node = 0, sum = 0, result = 0;
	bool isEnd = false;
	for(int i = 0; i < N; i++){
		node = i+1;
		level = 1;
		sum = 0;
		queue.push(-1);
		while(true){
			for(int j = 0; j < N; j++){
				if(graph[node][j+1] == 1 && Node[j+1] == 0){
					Node[j+1] = level;
					queue.push(j+1);
				}
			}
			if(queue.front() == -1){
				queue.pop();
				if(queue.empty()){
					break;
				}else{
					level++;
					queue.push(-1);
				}
			}
			node = queue.front();
			queue.pop();
		}
		for(int j = 0; j < N; j++){
			sum += Node[j+1];
			Node[j+1] = 0; // 초기화
		}
		if(min > sum){
			min = sum;
			result = i+1;
		}
	}
	
	cout << result << "\n";
	
	return 0;
}