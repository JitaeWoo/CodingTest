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
#define INF 10000000

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	
	vector<pair<int, int>> graph[n];
	vector<pair<int, int>>::iterator iter;
	int start = 0, end = 0, cost = 0;
	for(int i = 0; i < n-1; i++){
		cin >> start >> end >> cost;
		graph[start-1].push_back(make_pair(end-1, cost));
		graph[end-1].push_back(make_pair(start-1, cost));
	}
	
	int dist[n]={};
	for(int i = 0; i < n; i++){
		dist[i] = INF;
	}
	dist[0] = 0;
	
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int node = 0;
	while(!q.empty()){
		cost = -q.top().first;
		node = q.top().second;
		q.pop();
		for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
			if(dist[iter->first] > dist[node] + iter->second){
				dist[iter->first] = dist[node] + iter->second;
				q.push(make_pair(-dist[iter->first], iter->first));
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(max < dist[i] && dist[i] != INF){
			max = dist[i];
			node = i;
		}
		dist[i] = INF;
	}
	dist[node] = 0;
	q.push(make_pair(0, node));
	
	while(!q.empty()){
		cost = -q.top().first;
		node = q.top().second;
		q.pop();
		for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
			if(dist[iter->first] > dist[node] + iter->second){
				dist[iter->first] = dist[node] + iter->second;
				q.push(make_pair(-dist[iter->first], iter->first));
			}
		}
	}
	
	max = 0;
	for(int i = 0; i < n; i++){
		if(max < dist[i] && dist[i] != INF){
			max = dist[i];
		}
	}
	
	cout << max << "\n";
	
	return 0;
}