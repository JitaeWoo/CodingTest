#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    std::vector<std::vector<int>> cost(N, std::vector<int> (3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> cost[i][j];
        }
    }
    
    std::vector<std::vector<std::vector<int>>> DP(3, std::vector<std::vector<int>>(N, std::vector<int>(3))); 
    for(int i = 0; i < 3; i++){
        // 초기값 설정
        for(int j = 0; j < 3; j++){
            if(i == j){
                DP[i][1][j] = INF;
            }else{
                DP[i][1][j] = cost[0][i] + cost[1][j];
            }
        }
        
        // DP 생성
        int choice1[3] = { 1, 2, 0 };
        int choice2[3] = { 2, 0, 1 };
        for(int j = 2; j < N; j++){
            for(int k = 0; k < 3; k++){
                DP[i][j][k] = std::min(DP[i][j-1][choice1[k]], DP[i][j-1][choice2[k]]) + cost[j][k];
            }
        }
        DP[i][N-1][i] = INF;
    }
    
    int min = INF;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(min > DP[i][N-1][j]){
                min = DP[i][N-1][j];
            }
        }
    }
    
    std::cout << min << "\n";

    return 0;
}
