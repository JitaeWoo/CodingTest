#include <iostream>
#include <vector>
#include <algorithm>

class union_find{
    int* parent;

public:
    union_find(int N){
        parent = new int[N];
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            return parent[x] = find(parent[x]);
        }
    }
    
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x < y){
            parent[y] = x;
        }else{
            parent[x] = y;
        }
    }
};

int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(NULL);
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M >> K;
    
    std::vector<int> candies(N);
    for(int i = 0; i < N; i++){
        std::cin >> candies[i];
    }
    
    // 그룹으로 묶기
    union_find uf(N);
    std::vector<std::vector<int>> friends(M, std::vector<int>(2));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < 2; j++){
            std::cin >> friends[i][j];
            friends[i][j]--;
        }
        uf.merge(friends[i][0], friends[i][1]);
    }
    
    // 그룹별 캔디 수로 가공
    std::vector<int> count_candy(N);
    std::vector<int> count_firend(N);
    for(int i = 0; i < N; i++){
        count_candy[uf.find(i)] += candies[i];
        count_firend[uf.find(i)]++;
    }
    std::vector<std::pair<int, int>> group_candies;
    for(int i = 0; i < N; i++){
        if(count_candy[i] != 0){
            group_candies.push_back(std::make_pair(count_candy[i], count_firend[i]));
        }
    }
    
    // 가방 문제 풀기
    std::vector<std::vector<int>> DP(K, std::vector<int>(group_candies.size()+1));
    for(int i = 1; i < K; i++){
        for(int j = 1; j <= group_candies.size(); j++){
            if(i >= group_candies[j-1].second){
                DP[i][j] = std::max(group_candies[j-1].first + DP[i - group_candies[j-1].second][j - 1], DP[i][j-1]);
            }else{
                DP[i][j] = DP[i][j-1];
            }
        }
    }
    
    std::cout << DP[K-1][group_candies.size()] << "\n";
    
    return 0;
}
