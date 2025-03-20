#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    int N_array[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> N_array[i];
    }
    int N_index[N]={};
    
    std::vector<int> LIS;
    LIS.push_back(N_array[0]);
    N_index[0] = 0;
    for(int i = 1; i < N; i++){
        auto idx = std::lower_bound(LIS.begin(), LIS.end(), N_array[i]);
        if(idx == LIS.end()){
            LIS.push_back(N_array[i]);
            N_index[i] = LIS.size() - 1;
        }else{
            LIS[idx - LIS.begin()] = N_array[i];
            N_index[i] = idx - LIS.begin();
        }
    }
    
    std::cout << LIS.size() << "\n";
    
    std::vector<int> result;
    int index = LIS.size()-1;
    for(int i = N-1; i >= 0; i--){
        if(index == N_index[i]){
            result.push_back(N_array[i]);
            index--;
        }
    }
    
    for(int i = LIS.size()-1; i >= 0; i--){
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}