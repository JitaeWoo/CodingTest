#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::to_string;
using std::sort;

void NM(int NArray[], string result, int start, int length, int N, int M){
    static int check[10]={};
    if(length >= M){
        cout << result << "\n";
    }else{
        for(int i = 1; i <= N; i++){
            if(check[i] != 1){
                check[i] = 1;
                NM(NArray, result+to_string(NArray[i])+" ", i+1, length+1, N, M);
                check[i] = 0;
            }
           
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    int NArray[N+1]={};
    for(int i = 1; i <= N; i++){
        cin >> NArray[i];
    }
    sort(NArray, NArray+N+1);
    
    NM(NArray, "", 1, 0, N, M);
    
   return 0;
}