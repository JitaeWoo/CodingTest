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
	int n = 0, m = 0;
	cin >> n >> m;
	
	vector<pair<int, int>> bus[n+1];
	vector<pair<int, int>>::iterator iter;
	int start = 0, end = 0, cost = 0;
	for(int i = 0; i < m; i++){
		cin >> start >> end >> cost;
		bus[start].push_back(make_pair(end, cost));
	}
	
	int dist[n+1][n+1]={}; // 거리 저장 배열
	for(int i = 1; i <= n; i++){ // 초기화
		for(int j = 1; j <= n; j++){
			if(i == j){
				dist[i][j] = 0;
			}else{
				dist[i][j] = 100000000;
			}
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		priority_queue<pair<int, int>> q;
		q.push(make_pair(0, i));
		int node = i;
		
		while(!q.empty()){
			int cost = -q.top().first;
			int node = q.top().second;
			q.pop();
			
			for(iter = bus[node].begin(); iter != bus[node].end(); iter++){
				if(cost + iter->second < dist[i][iter->first]){
					dist[i][iter->first] = cost + iter->second;
					q.push(make_pair(-dist[i][iter->first], iter->first));
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dist[i][j] == 100000000){
				cout << "0 ";
			}else{
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}