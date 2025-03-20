#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;
using std::vector;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<pair<int, int>> bus[n+1];
    int start = 0, end = 0, cost = 0;
    for(int i = 0; i < m; i++){
        cin >> start >> end >> cost;
        bus[start].push_back(make_pair(end, cost));
    }
    
    cin >> start >> end;
    
    int dist[n+1]={};
    for(int i = 1; i <= n; i++){
        dist[i] = 100000000;
    }
    dist[start] = 0;
	int before[n+1]={};
	int check[n+1]={};
	check[start] = 1;
	int node = start;
	cost = 0;
    for(int i = 0; i < n-1; i++){
		if(node == end){
			break;
		}
        
        for(pair<int, int> b : bus[node]){
            if(dist[b.first] > cost + b.second){
                dist[b.first] = cost + b.second;
				before[b.first] = node;
            }
        }
		
		int min = 1000000000, minNode = 0;
		for(int j = 1; j <= n; j++){
			if(check[j] != 1){
				if(min > dist[j]){
					min = dist[j];
					minNode = j;
				}
			}
		}
		
		check[minNode] = 1;
		node = minNode;
		cost = min;
    }
    
	
	int count = 1;
	int route[n+1]={};
	route[count] = end;
	node = end;
	while(node != start){
		node = before[node];
		count++;
		route[count] = node;
	}
	
	cout << dist[end] << "\n";
	cout << count << "\n";
	for(int i = count; i > 0; i--){
		cout << route[i] << " ";
	}
	cout << "\n";
	
    
    return 0;
}