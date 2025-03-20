#include <iostream>
#include <vector>
#include <algorithm>

int find(int parent[], int x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = find(parent, parent[x]);
    }
}

void merge(int parent[], int x, int y){
    x = parent[x];
    y = parent[y];
    
    if(x > y){
        parent[x] = y;
    }else{
        parent[y] = x;
    }
}

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    std::vector<std::pair<int, std::pair<int, int>>> roads;
    for(int i = 0; i < M; i++){
        int A = 0, B = 0, C = 0;
        std::cin >> A >> B >> C;
        
        roads.push_back(std::make_pair(C, std::make_pair(A, B)));
    }
    
    std::sort(roads.begin(), roads.end());
    
    int parent[N+1]={};
    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }
    
    int result = 0, roads_num = 0;
    for(std::pair<int, std::pair<int, int>> r : roads){
        if(find(parent, r.second.first) != find(parent, r.second.second)){
            if(roads_num >= N-2){
                break;
            }
            result += r.first;
            merge(parent, r.second.first, r.second.second);
            roads_num++;
        }
    }
    
    std::cout << result << "\n";
    
    return 0;
}