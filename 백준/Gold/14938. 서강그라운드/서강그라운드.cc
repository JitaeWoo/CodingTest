#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;
using std::vector;
using std::priority_queue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n = 0, m = 0, r = 0;
	cin >> n >> m >> r;
	
	int item[n+1]={};
	for(int i = 1; i <= n; i++){
		cin >> item[i];
	}
	
	vector<pair<int, int>> road[n+1];
	for(int i = 0; i < r; i++){
		int start = 0, end = 0, cost = 0;
		cin >> start >> end >> cost;
		
		road[start].push_back(make_pair(end, cost));
		road[end].push_back(make_pair(start, cost));
	}
	
	priority_queue<pair<int, int>> q;
	int dist[n+1][n+1]={};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = 100000;
		}
	}
	
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
		q.push(make_pair(0, i));
		while(!q.empty()){
			int cost = -q.top().first;
			int node = q.top().second;
			q.pop();
			
			for(pair<int, int> TRoad : road[node]){
				if(cost + TRoad.second < dist[i][TRoad.first]){
					dist[i][TRoad.first] = cost + TRoad.second;
					q.push(make_pair(-dist[i][TRoad.first], TRoad.first));
				}
			}
		}
	}
	
	int max = 0, result = 0;
	for(int i = 1; i <= n; i++){
		max = 0;
		for(int j = 1; j <= n; j++){
			if(dist[i][j] <= m){
				max += item[j];
			}
		}
		if(result < max){
			result = max;
		}
	}
	
	cout << result << "\n";
    
    return 0;
}