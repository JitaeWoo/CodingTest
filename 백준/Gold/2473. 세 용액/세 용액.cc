#include <iostream>
#include <cstdlib>
#include <algorithm>
#define INF 4100000000

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    long long arr[N]={};
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    
    std::sort(arr, arr+N);
    
    long long min = INF;
    int min_x = 0;
    int min_y = 0;
    int min_z = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            long long sum = arr[i] + arr[j];
            int head = 0;
            int tail = N-1;
            while(head == i || head == j){
                head++;
            }
            while(tail == i || tail == j){
                tail--;
            }
            
            long long result = 0;
            while(head <= tail){
                int m = (head + tail) / 2;
                while(m == i || m == j){
                    m++;
                }
                if(m < 0 || m > N-1){
                    break;
                }
                result = sum + arr[m];
                if(labs(result) < min){
                    min = labs(result);
                    min_x = i;
                    min_y = j;
                    min_z = m;
                }
                
                if(result == 0){
                    long long output[3]={arr[i], arr[j], arr[m]};
                    std::sort(output, output+3);
                    for(int k = 0; k < 3; k++){
                        std::cout << output[k] << " ";
                    }
                    std::cout << "\n";
                    return 0;
                }else if(result < 0){
                    head = m + 1;
                }else{
                    tail = m - 1;
                }
                while(head == i || head == j){
                    head++;
                }
                while(tail == i || tail == j){
                    tail--;
                }
            }
        }
    }
    long long output[3]={arr[min_x], arr[min_y], arr[min_z]};
    std::sort(output, output+3);
    for(int k = 0; k < 3; k++){
        std::cout << output[k] << " ";
    }
    std::cout << "\n";
    
    return 0;
}