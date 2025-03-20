#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    cin >> N;
    
    int NArray1[N+1]={}, NArray2[N+1]={};
    int num = 0;
    for(int i = 1; i <= N; i++){
        cin >> num;
        NArray1[i] = num;
        NArray2[N-i+1] = num;
    }
    
    int DP1[N+1]={}, DP2[N+1]={};
    for(int i = 1; i <= N; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(NArray1[j] < NArray1[i] && DP1[j] > max){
                max = DP1[j];
            }
        }
        DP1[i] = max+1;
        
        max = 0;
        for(int j = 0; j < i; j++){
            if(NArray2[j] < NArray2[i] && DP2[j] > max){
                max = DP2[j];
            }
        }
        DP2[i] = max+1;
    }
    
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(DP1[i] + DP2[N-i+1] > max){
            max = DP1[i] + DP2[N-i+1];
        }
    }
    
    cout << max-1 << "\n";
    
    
    return 0;
}