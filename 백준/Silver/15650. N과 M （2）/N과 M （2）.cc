#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::to_string;

void NM(string result, int start, int length, int N, int M){
    if(length >= M){
        cout << result << "\n";
    }else{
        for(int i = start; i <= N; i++){
            NM(result+to_string(i)+" ", i+1, length+1, N, M);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    NM("", 1, 0, N, M);
    
   return 0;
}