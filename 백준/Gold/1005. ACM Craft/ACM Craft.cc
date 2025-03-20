#include <iostream>
#include <vector>
#include <queue>

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int T = 0;
	std::cin >> T;
	
	for(int i = 0; i < T; i++){
		int N = 0, K = 0;
		std::cin >> N >> K;
		
		int D[N+1]={};
		for(int j = 1; j <= N; j++){
			std::cin >> D[j];
		}
		
		std::vector<int> rules[N+1];
		for(int j = 0; j < K; j++){
			int start = 0, end = 0;
			std::cin >> start >> end;
			rules[end].push_back(start);
		}
		
		int W = 0;
		std::cin >> W;
		
		std::queue<int> q;
		int delay[N+1]={};
		for(int j = 1; j <= N; j++){
			delay[j] = -1;
		}
		for(int j = 1; j <= N; j++){
			// 시작지점에 해당하는 노드라면
			if(rules[j].empty()){
				delay[j] = D[j];
			}else{
				q.push(j);
			}
		}
		
		int result = 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			
			bool is_ready = true;
			for(int n : rules[node]){
				if(delay[n] == -1){
					is_ready = false;
				}
			}
			if(!is_ready){
				q.push(node);
				continue;
			}
			
			int max = 0;
			for(int d : rules[node]){
				if(max < delay[d]){
					max = delay[d];
				}
			}
			
			delay[node] = max+D[node];
			if(node == W){
				break;
			}
		}
		
		std::cout << delay[W] << "\n";
	}
	
    return 0;
}