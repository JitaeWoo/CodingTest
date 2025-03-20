#include <iostream>
#include <cstdlib>
#define INF 2100000000

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    int arr[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    
    int min = INF;
    int min_x = 0;
    int min_y = 0;
    for(int i = 0; i < N; i++){
        int head = 0;
        int tail = N-1;
        if(head == i){
            head++;
        }
        if(tail == i){
            tail--;
        }
        
        int result = 0;
        while(head <= tail){
            int m = (head + tail) / 2;
            result = arr[i] + arr[m];
            if(abs(result) < min){
                min = abs(result);
                min_x = i;
                min_y = m;
            }
            
            if(result == 0){
                if(i < m){
                    std::cout << arr[i] << " " << arr[m] << "\n";
                }else{
                    std::cout << arr[m] << " " << arr[i] << "\n";
                }
                return 0;
            }else if(result < 0){
                head = m + 1;
            }else{
                tail = m - 1;
            }
            if(head == i){
                head++;
            }
            if(tail == i){
                tail--;
            }
        }
    }
    
    if(min_x < min_y){
        std::cout << arr[min_x] << " " << arr[min_y] << "\n";
    }else{
        std::cout << arr[min_y] << " " << arr[min_x] << "\n";
    }
    
    return 0;
}