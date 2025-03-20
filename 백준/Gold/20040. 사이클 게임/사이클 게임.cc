#include <iostream>
#include <vector>

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
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> m_v(m, std::vector<int>(2));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            std::cin >> m_v[i][j];
        }
    }
    
    union_find uf(n);
    int turn = 1;
    int result = 0;
    for(int i = 0; i < m; i++){
        int p1 = m_v[i][0];
        int p2 = m_v[i][1];
        
        if(uf.find(p1) == uf.find(p2)){
            result = turn;
            break;
        }else{
            uf.merge(p1, p2);
            turn++;
        }
    }
    
    std::cout << result << "\n";
    
    return 0;
}
