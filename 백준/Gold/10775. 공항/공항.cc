#include <iostream>

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
        x = parent[x];
        y = parent[y];
        
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
    int G = 0, P = 0;
    std::cin >> G >> P;
    
    int g[P]={};
    for(int i = 0; i < P; i++){
        std::cin >> g[i];
    }
    
    union_find uf(G+1);
    int result = 0;
    for(int i = 0; i < P; i++){
        int gate = uf.find(g[i]);
        if(gate != 0){
            result++;
            uf.merge(gate, gate-1);
        }else{
            break;
        }
    }
    
    std::cout << result << "\n";

    return 0;
}
