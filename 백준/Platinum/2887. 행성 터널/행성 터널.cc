#include <iostream>
#include <algorithm>
#include <queue>

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
        
        if(x > y){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    std::pair<int, int> x_array[N]={}, y_array[N]={}, z_array[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> x_array[i].first >> y_array[i].first >> z_array[i].first;
        x_array[i].second = i;
        y_array[i].second = i;
        z_array[i].second = i;
    }
    
    std::sort(x_array, x_array+N);
    std::sort(y_array, y_array+N);
    std::sort(z_array, z_array+N);
    
    std::priority_queue<std::pair<int, std::pair<int, int>>> q;
    for(int i = 0; i < N-1; i++){
        q.push(std::make_pair(-std::abs(x_array[i].first - x_array[i+1].first), std::make_pair(x_array[i].second, x_array[i+1].second)));
        q.push(std::make_pair(-std::abs(y_array[i].first - y_array[i+1].first), std::make_pair(y_array[i].second, y_array[i+1].second)));
        q.push(std::make_pair(-std::abs(z_array[i].first - z_array[i+1].first), std::make_pair(z_array[i].second, z_array[i+1].second)));
    }
    
    union_find uf(N);
    int result = 0;
    for(int i = 0; i < N-1; i++){
        int df = -q.top().first;
        int a = q.top().second.first;
        int b = q.top().second.second;
        q.pop();
        
        if(uf.find(a) == uf.find(b)){
            i--;
        }else{
            uf.merge(a, b);
            result += df;
        }
    }
    
    std::cout << result << "\n";

    return 0;
}
