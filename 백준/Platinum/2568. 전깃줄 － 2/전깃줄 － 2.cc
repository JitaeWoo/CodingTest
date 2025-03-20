#include <iostream>
#include <algorithm>
#include <vector>
#define pii std::pair<int,int>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    pii N_array[N];
    for(int i = 0; i < N; i++){
        std::cin >> N_array[i].first >> N_array[i].second;
    }
    
    std::sort(N_array, N_array+N);
    
    std::vector<int> LIS;
    int N_index[N]={};
    LIS.push_back(N_array[0].second);
    N_index[0] = 0;
    for(int i = 1; i < N; i++){
        auto index = std::lower_bound(LIS.begin(), LIS.end(), N_array[i].second);
        if(index == LIS.end()){
            LIS.push_back(N_array[i].second);
            N_index[i] = LIS.size() - 1;
        }else{
            LIS[index - LIS.begin()] = N_array[i].second;
            N_index[i] = index - LIS.begin();
        }
    }
    
    std::cout << N - LIS.size() << "\n";
    
    bool result[N]={};
    int max = LIS.size()-1;
    for(int i = N-1; i >= 0; i--){
        if(N_index[i] == max){
            result[i] = true;
            max--;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(!result[i]){
            std::cout << N_array[i].first << "\n";
        }
    }

    return 0;
}
