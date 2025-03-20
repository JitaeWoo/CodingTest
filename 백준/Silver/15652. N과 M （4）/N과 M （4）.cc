#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::to_string;

void NM(int N, int M, int start, int count, string result){
    if(count >= M){
        cout << result << "\n";
        return;
    }else{
        for(int i = start; i <= N; i++){
            NM(N, M, i, count+1, result+to_string(i)+" ");
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    NM(N, M, 1, 0, "");
    
    return 0;
}