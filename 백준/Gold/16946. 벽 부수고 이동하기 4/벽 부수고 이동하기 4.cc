#include <iostream>
#include <set>
#include <queue>
#define pii std::pair<int,int>

class break_block{
    int map[1001][1001];
    int dn[4] = {-1, 1, 0, 0};
    int dm[4] = {0, 0, -1, 1};
    int N;
    int M;
public:
    break_block(int N, int M){
        this->N = N;
        this->M = M;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                char c;
                std::cin >> c;
                map[i][j] = c - 48;
            }
        }
    }
    
    int move(int n, int m, int checker){
        int result = 1;
        std::queue<pii> q;
        q.push(std::make_pair(n, m));
        while(!q.empty()){
            n = q.front().first;
            m = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int cn = n + dn[i];
                int cm = m + dm[i];
                if(cn < 0 || cn >= N || cm < 0 || cm >= M){
                    continue;
                } 
                
                if(map[cn][cm] == 0){
                    map[cn][cm] = checker;
                    result++;
                    q.push(std::make_pair(cn, cm));
                }
            }
        }
        
        return result;
    }
    
    void count(){
        int checker = 2;
        int counts[500000]={};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0){
                    map[i][j] = checker;
                    counts[checker] = move(i, j, checker);
                    checker++;
                }
            }
        }
        
        std::set<int> s; 
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        if(i+dn[k] < 0 || i + dn[k] >= N || j + dm[k] < 0 || j + dm[k] >= M){
                            continue;
                        }
                        if(map[i+dn[k]][j+dm[k]] == 1){
                            continue;
                        }
                        s.insert(map[i+dn[k]][j+dm[k]]);
                    }
                    
                    int result = 0;
                    for(int num : s){
                        result += counts[num];
                    }
                    s.clear();
                    
                    std::cout << (result+1) % 10;
                }else{
                    std::cout << '0';
                }
            }
            std::cout << "\n";
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    break_block bb(N, M);
    bb.count();
    
    return 0;
}
