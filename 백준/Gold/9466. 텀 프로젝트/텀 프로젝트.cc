#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T = 0;
    std::cin >> T;
    
    
    bool check[100001]={};
    std::vector<int> v;
    for(int i = 0; i < T; i++){
        int n = 0;
        std::cin >> n;
        
        int n_array[n+1]={};
        for(int i = 1; i <= n; i++){
            std::cin >> n_array[i];
        }
        
        int result = n;
        for(int i = 1; i <= n; i++){
            int node = i;
            if(check[node]){
                continue;
            }
            check[node] = true;
            v.push_back(node);
            
            while(!check[n_array[node]]){
                v.push_back(n_array[node]);
                check[n_array[node]] = true;
                node = n_array[node];
            }
            
            for(int j = 0; j < v.size(); j++){
                if(v[j] == n_array[node]){
                    result -= v.size() - j;
                    break;
                }
            }
            
            v.clear();
        }
        
        std::cout << result << "\n";
        
        for(int j = 1; j <= n; j++){
            check[j] = false;
        }
    }
    
    return 0;
}