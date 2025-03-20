#include <iostream>
#include <set>

class union_find{
    int* parent;
    int N;
public:
    union_find(int N){
        parent = new int[N];
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
        this->N = N;
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
    
    int count_group(){
        std::set<int> s;
        for(int i = 0; i < N; i++){
            s.insert(find(i));
        }
        
        return s.size();
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    union_find uf(N*M);
    char board[N][M]={};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char direction[4] = {'U', 'D', 'L', 'R'};
            int dn[4] = {-1, 1, 0, 0};
            int dm[4] = {0, 0, -1, 1};
            
            for(int k = 0; k < 4; k++){
                if(board[i][j] == direction[k]){
                    uf.merge(i*M + j, (i+dn[k])*M + (j+dm[k]));
                    break;
                }
            }
        }
    }
    
    std::cout << uf.count_group() << "\n";
    
    return 0;
}
