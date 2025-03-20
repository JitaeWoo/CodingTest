#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    std::vector<int> N_v(N);
    std::vector<int> check(1000001);
    std::vector<int> score(1000001);
    for(int i = 0; i < N; i++){
        std::cin >> N_v[i];
        check[N_v[i]]++;
    }
    
    for(int i = 1; i < 500001; i++){
        if(check[i] != 0){
            for(int j = 2; j*i < 1000001; j++){
                if(check[j*i] != 0){
                    score[j*i]--;
                    score[i]++;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        std::cout << score[N_v[i]] << " ";
    }
    std::cout << "\n";

    return 0;
}
