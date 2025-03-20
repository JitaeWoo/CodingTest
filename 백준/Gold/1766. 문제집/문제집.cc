#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    std::vector<std::pair<int, int>> hint;
    int edge[N+1]={};
    for(int i = 0; i < M; i++){
        int A = 0, B = 0;
        std::cin >> A >> B;
        
        hint.push_back(std::make_pair(A, B));
        edge[B]++;
    }
    
    std::priority_queue<int> q;
    for(int i = 1; i <= N; i++){
        if(edge[i] == 0){
            q.push(-i);
        }
    }
    
    while(!q.empty()){
        int question = -q.top();
        q.pop();
        
        std::cout << question << " ";
        
        for(std::pair<int, int> p : hint){
            if(p.first == question){
                if(--edge[p.second] == 0){
                    q.push(-p.second);
                }
            }
        }
    }
    
    std::cout << "\n";
    
    return 0;
}