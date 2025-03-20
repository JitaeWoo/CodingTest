#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::to_string;
using std::sort;

void NM(int NArray[], int N, int M, int start, int count, string result){
    if(count >= M){
        cout << result << "\n";
        return;
    }else{
        for(int i = start; i < N; i++){
            NM(NArray, N, M, i, count+1, result+to_string(NArray[i])+" ");
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    int NArray[N]={};
    for(int i = 0; i < N; i++){
        cin >> NArray[i];
    }
    sort(NArray, NArray+N);
    
    NM(NArray, N, M, 0, 0, "");
    
    return 0;
}