#include <iostream>
#include <queue>
#include <cmath>
#define pdd std::pair<double,double>

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

double diff(pdd point1, pdd point2){
    double x_diff = pow(point1.first - point2.first, 2);
    double y_diff = pow(point1.second - point2.second, 2);
    
    return sqrt(x_diff + y_diff);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = 0;
    std::cin >> n;
    
    pdd n_array[n];
    for(int i = 0; i < n; i++){
        std::cin >> n_array[i].first >> n_array[i].second;
    }
    
    std::priority_queue<std::pair<double, std::pair<int, int>>> q;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double difference = diff(n_array[i], n_array[j]);
            q.push(std::make_pair(-difference, std::make_pair(i, j)));
        }
    }
    
    union_find uf(n);
    double result = 0;
    for(int i = 0; i < n-1; i++){
        double c_diff = q.top().first;
        int star1 = q.top().second.first;
        int star2 = q.top().second.second;
        q.pop();
        
        if(uf.find(star1) == uf.find(star2)){
            i--;
        }else{
            result += -c_diff;
            uf.merge(star1, star2);
        }
    }
    
    std::cout << result << "\n";
    
    
    return 0;
}
