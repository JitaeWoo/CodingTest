#include <iostream>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    std::pair<int, int> comparison[M];
    int edge[N+1]={};
    for(int i = 0; i < M; i++){
        std::cin >> comparison[i].first >> comparison[i].second;
        edge[comparison[i].second]++;
    }
    
    std::priority_queue<int> q;
    for(int i = 1; i <= N; i++){
        if(edge[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int student = q.top();
        q.pop();
        std::cout << student << " ";
        
        for(int i = 0; i < M; i++){
            if(comparison[i].first == student){
                if(--edge[comparison[i].second] == 0){
                    q.push(comparison[i].second);
                }
            }
        }
    }
    
    std::cout << "\n";
    
    
    return 0;
}