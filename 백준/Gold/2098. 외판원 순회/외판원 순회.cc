#include <iostream>
#define INF 999999999

class TSP{
    int DP[16][1 << 16];
    int W[16][16];
    int N;
    
public:
    TSP(int N){
        this->N = N;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                std::cin >> W[i][j];
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < (1 << N); j++){
                DP[i][j] = -1;
            }
        }
    }
    
    int count(int cur, int visited){
        if(visited == (1 << N) - 1){
            if(W[cur][0] == 0){ // 처음으로 못 돌아가면
                return INF;
            }else{
                return W[cur][0];
            }
        }
        
        if(DP[cur][visited] != -1){
            return DP[cur][visited];
        }
        
        DP[cur][visited] = INF;
        
        for(int i = 1; i < N; i++){
            if(W[cur][i] == 0){ // 길이 없으면
                continue;
            }
            if(visited & (1 << i)){ // 이미 방문했으면
                continue;
            }
            int temp = W[cur][i] + count(i, visited | 1 << i);
            DP[cur][visited] = DP[cur][visited] < temp ? DP[cur][visited] : temp;
        }
        
        return DP[cur][visited];
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    TSP t = TSP(N);
    
    int result = t.count(0, 1);
    
    std::cout << result << "\n";
    
    return 0;
}