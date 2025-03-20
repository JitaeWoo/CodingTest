#include <iostream>
#define INF 2147483647;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    std::pair<int, int> matrixs[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> matrixs[i].first >> matrixs[i].second;
    }
    
    int DP[N][N]={}; // DP[x][y] : x부터 y까지의 행렬곱 연산 최소값
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                DP[i][j] = INF;
            }
        }
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N-i; j++){
            for(int k = 0; k < i; k++){
                int temp = DP[j][j+k] + DP[j+k+1][j+i];
                temp += matrixs[j].first * matrixs[j+k].second * matrixs[j+i].second;
                if(DP[j][j+i] > temp){
                    DP[j][j+i] = temp;
                }
            }
        }
    }
    
    std::cout << DP[0][N-1] << "\n";
    
    return 0;
}