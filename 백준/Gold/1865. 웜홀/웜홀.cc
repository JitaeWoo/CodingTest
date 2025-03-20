#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::pair;
using std::make_pair;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int TC = 0;
	cin >> TC;
	
	int N = 0, M = 0, W = 0;
	for(int i = 0; i < TC; i++){
		cin >> N >> M >> W;
		vector<pair<int, int>> graph[N];
		vector<pair<int, int>>::iterator iter;
		int dist[N]={};
		for(int i = 0; i < N; i++){
			dist[i] = 10000000;
		}
		dist[0] = 0;
		
		int S = 0, E = 0, T = 0;
		for(int j = 0; j < M; j++){
			cin >> S >> E >> T;
			graph[S-1].push_back(make_pair(E-1, T));
			graph[E-1].push_back(make_pair(S-1, T));
		}
		
		for(int j = 0; j < W; j++){
			cin >> S >> E >> T;
			graph[S-1].push_back(make_pair(E-1, -T));
		}
		
		int node = 0, cost = 0;
		for(int j = 0; j < N-1; j++){
			node = j;
			for(int k = 0; k < N; k++){
				for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
					cost = dist[node] + iter->second;
					if(dist[iter->first] > cost){
						dist[iter->first] = cost;
					}
				}
				node = (node+1)%N;
			}
		}
		
		node = N-1;
		bool isLoop = false;
		for(int j = 0; j < N; j++){
			for(iter = graph[node].begin(); iter != graph[node].end(); iter++){
				cost = dist[node] + iter->second;
				if(dist[iter->first] > cost){
					isLoop = true;
					break;
				}
			}
			if(isLoop){
				break;
			}
			node = (node+1)%N;
		}
		if(isLoop){
			cout << "YES\n"; 
		}else{
			cout << "NO\n";
		}
	}
	
	return 0;
}