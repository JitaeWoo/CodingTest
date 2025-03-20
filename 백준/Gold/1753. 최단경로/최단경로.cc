#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::pair;
using std::make_pair;
using std::priority_queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V = 0, E = 0, K = 0;
	cin >> V >> E >> K;
	K -= 1;
	
	vector<pair<int, int>> graph[V];
	vector<pair<int, int>>::iterator iter;
	int start = 0, end = 0, weight = 0;
	for(int i = 0; i < E; i++){
		cin >> start >> end >> weight;
		graph[start-1].push_back(make_pair(end-1, weight));
	}
	
	int node = 0, cost = 0;
	int check[V]={}; // 방문 체크 용
	int distance[V]={}; // 최단거리 저장 배열
	for(int i = 0; i < V; i++){
		distance[i] = 1000000;
	}
	distance[K] = 0;
	
	priority_queue<pair<int, int>> q;
	check[node] = 1;
	
	q.push(make_pair(0, K));
	while(!q.empty()){
		cost = -q.top().first;
		node = q.top().second;
		q.pop();
		for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
			if(distance[iter->first] > cost + iter->second){
				distance[iter->first] = cost + iter->second;
				q.push(make_pair(-distance[iter->first], iter->first));
			}
		}
	}
	
	for(int i = 0; i < V; i++){
		if(distance[i] == 1000000){
			cout << "INF\n";
		}else{
			cout << distance[i] << "\n";
		}
	}
	
	return 0;
}