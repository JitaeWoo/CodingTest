#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, S = 0;
    std::cin >> N >> S;
    
    int N_array[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> N_array[i];
    }
    
    int result = 100001;
    int sum = 0;
    int i = 0, j = 0;
    bool op = true;
    while(true){
        if(op){
            if(i >= N){
                break;
            }
            sum += N_array[i++];
            if(sum >= S){
                op = false;
                if(result > i - j){
                    result = i - j;
                }
            }
        }else{
            sum -= N_array[j++];
            if(sum < S){
                op = true;
                if(result > i - j + 1){
                    result = i - j + 1;
                }
            }
        }
    }
    
    if(result != 100001){
        std::cout << result << "\n";
    }else{
        std::cout << "0\n";
    }
    
    return 0;
}