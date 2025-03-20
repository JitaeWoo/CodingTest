#include <iostream>
#include <algorithm>
#include <queue>

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int N = 0, K = 0;
	std::cin >> N >> K;
	
	std::pair<int, int> gems[N];
	for(int i = 0; i < N; i++){
		int M = 0, V = 0;
		std::cin >> M >> V;
		
		gems[i] = std::make_pair(M, V);
	}
	std::sort(gems, gems+N);
	
	int C[K]={};
	for(int i = 0; i < K; i++){
		std::cin >> C[i];
	}
	std::sort(C, C+K);
	
	std::priority_queue<int> q;
	int idx = 0;
	long long result = 0;
	for(int i = 0; i < K; i++){
		while(idx < N && gems[idx].first <= C[i]){
			q.push(gems[idx].second);
			idx++;
		}
		
		if(!q.empty()){
			result += q.top();
			q.pop();
		}
	}
	
	std::cout << result << "\n";
	
    return 0;
}