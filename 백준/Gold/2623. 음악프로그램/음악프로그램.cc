#include <iostream>
#include <vector>
#include <queue>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    int edge[N+1]={};
    int check[N+1][N+1]={};
    std::vector<std::pair<int, int>> prior;
    for(int i = 0; i < M; i++){
        int seq = 0;
        std::cin >> seq;
        int a = 0, b = 0;
        std::cin >> a;
        for(int j = 0; j < seq-1; j++){
            std::cin >> b;
            if(check[b][a] == 0){
                edge[b]++;
                check[b][a] = 1;
                prior.push_back(std::make_pair(b, a));
            }
            a = b;
        }
    }
    
    std::priority_queue<int> q;
    for(int i = 1; i <= N; i++){
        if(edge[i] == 0){
            q.push(i);
        }
    }
    
    std::vector<int> result;
    while(!q.empty()){
        int singer = q.top();
        q.pop();
        result.push_back(singer);
        
        for(std::pair<int, int> pr : prior){
            if(pr.second == singer){
                if(--edge[pr.first] == 0){
                   q.push(pr.first);
                }
            }
        }
    }
    
    if(result.size() == N){
        for(int r : result){
            std::cout << r << "\n";
        }
    }else{
        std::cout << "0\n";
    }
    
    return 0;
}