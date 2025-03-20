#include <iostream>
#include <algorithm>
#define INF 99999999

class smartphone{
    int DP[101][10001];
    int memory[101];
    int cost[101];
    int N;
    int M;
    int min;
public:
    smartphone(int N, int M){
        this->N = N;
        this->M = M;
        min = INF;
        for(int i = 1; i <= N; i++){
            std::cin >> memory[i];
        }
        
        for(int i = 1; i <= N; i++){
            std::cin >> cost[i];
        }
    }
    
    int count(){
        int j = 0;
        while(true){
            for(int i = 1; i <= N; i++){
                if(cost[i] <= j){
                    DP[i][j] = std::max(memory[i] + DP[i-1][j-cost[i]], DP[i-1][j]);
                }else{
                    DP[i][j] = DP[i-1][j];
                }
                
                if(DP[i][j] >= M){
                    return j;
                }
            }
            j++;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    smartphone sp(N, M);
    
    int result = sp.count();
    
    std::cout << result << "\n";
    
    return 0;
}