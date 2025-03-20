#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    int N_array[N+1]={};
    for(int i = 1; i <= N; i++){
        std::cin >> N_array[i];
    }
    
    bool DP[N+1][N+1]={}; // DP[x][y] : x 부터 y가 펠린드롬인가?
    
    // 하나짜리는 다 true
    for(int i = 1; i <= N; i++){
        DP[i][i] = true;
    }
    
    // 2칸은 서로 같으면 true
    for(int i = 1; i < N; i++){
        if(N_array[i] == N_array[i+1]){
            DP[i][i+1] = true;
        }
    }
    
    // 3칸부터 양쪽 끝이 같고 사이가 펠린드롬이면 true;
    for(int i = 2; i < N; i++){
        for(int j = 1; j <= N - i; j++){
            if(N_array[j] == N_array[j+i] && DP[j+1][j+i-1]){
                DP[j][j+i] = true;
            }
        }
    }
    
    int M = 0; 
    std::cin >> M;
    
    for(int i = 0; i < M; i++){
        int S = 0, E = 0;
        std::cin >> S >> E;
        
        if(DP[S][E]){
            std::cout << "1\n";
        }else{
            std::cout << "0\n";
        }
    }
    
    return 0;
}