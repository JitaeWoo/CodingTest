#include <iostream>
#include <algorithm>
#include <vector>

int find(int parent[], int x){
	if(parent[x] == x){
		return x;
	}else{
		return parent[x] = find(parent, parent[x]);
	}
}

void Union(int parent[], int x, int y){
	x = find(parent, x);
	y = find(parent, y);
	
	if(x < y){
		parent[y] = x;
	}else{
		parent[x] = y;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int V = 0, E = 0;
	std::cin >> V >> E;
	
	std::vector<std::pair<int, std::pair<int, int>>> edge;
	for(int i = 0; i < E; i++){
		int A = 0, B = 0, C = 0;
		std::cin >> A >> B >> C;
		
		edge.push_back(std::make_pair(C, std::make_pair(A, B)));
	}
	std::sort(edge.begin(), edge.end());
	
	int parent[V+1]={};
	for(int i = 1; i <= V; i++){
		parent[i] = i;
	}
	
	int result = 0, checked_edge = 0;
	for(std::pair<int, std::pair<int, int>> e : edge){
		if(checked_edge >= V-1){
			break;
		}
		
		int node1 = e.second.first, node2 = e.second.second;
		
		if(find(parent, node1) != find(parent, node2)){
			Union(parent, node1, node2);
			checked_edge++;
			result += e.first;
		}
	}
	
	std::cout << result << "\n";
	
    return 0;
}