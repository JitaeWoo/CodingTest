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
#define INF 200000000

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	vector<pair<int, int>> graph[N];
	vector<pair<int, int>>::iterator iter;
	int start = 0, end = 0, cost = 0;
	for(int i = 0; i < M; i++){
		cin >> start >> end >> cost;
		graph[start-1].push_back(make_pair(end-1, cost));
	}
	
	int S = 0, E = 0;
	cin >> S >> E;
	S--; E--;
	
	int dist[N]={};
	for(int i = 0; i < N; i++){
		dist[i] = INF;
	}
	dist[S] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, S));
	int node = 0;
	while(!q.empty()){
		cost = -q.top().first;
		node = q.top().second;
		if(node == E){
			break;
		}
		q.pop();
		for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
			if(dist[iter->first] > dist[node] + iter->second){
				dist[iter->first] = dist[node] + iter->second;
				q.push(make_pair(-dist[iter->first], iter->first));
			}
		}
	}
	
	cout << dist[E] << "\n";
	
	return 0;
}