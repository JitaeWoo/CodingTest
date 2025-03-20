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
    
    std::vector<int> LIS;
    LIS.push_back(N_array[0]);
    for(int i = 1; i < N; i++){
        auto idx = std::lower_bound(LIS.begin(), LIS.end(), N_array[i]);
        if(idx == LIS.end()){
            LIS.push_back(N_array[i]);
        }else{
            LIS[idx - LIS.begin()] = N_array[i];
        }
    }
    
    std::cout << LIS.size() << "\n";
    
    return 0;
}