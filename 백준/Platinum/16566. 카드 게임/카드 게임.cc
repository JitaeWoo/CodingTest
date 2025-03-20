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
        x = parent[x];
        y = parent[y];
        
        if(x < y){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M >> K;
    
    std::vector<int> M_v;
    for(int i = 0; i < M; i++){
        int Mx = 0;
        std::cin >> Mx;
        M_v.push_back(Mx);
    }
    union_find uf(M+1);
    std::sort(M_v.begin(), M_v.end());
    
    int K_array[K]={};
    for(int i = 0; i < K; i++){
        std::cin >> K_array[i];
    }
    
    for(int i = 0; i < K; i++){
        auto temp = std::upper_bound(M_v.begin(), M_v.end(), K_array[i]);
        
        if(temp == M_v.end()){
            std::cout << M_v[uf.find(0)] << "\n";
            uf.merge(0, uf.find(0)+1);
        }else{
            int index = temp - M_v.begin();
            std::cout << M_v[uf.find(index)] << "\n";
            uf.merge(index, uf.find(index) + 1);
        }
    }

    return 0;
}
