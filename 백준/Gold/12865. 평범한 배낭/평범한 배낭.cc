#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, K = 0;
    cin >> N >> K;
    
    pair<int, int> item[N+1];
    item[0] = make_pair(0, 0);
    for(int i = 1; i <= N; i++){
        cin >> item[i].first >> item[i].second;
    }
    
    int DP[N+1][K+1]={};
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= N; j++){
            if(item[j].first <= i){
                DP[j][i] = DP[j-1][i] >DP[j-1][i-item[j].first] + item[j].second ? 
                DP[j-1][i] : DP[j-1][i-item[j].first] + item[j].second;
            }else{
                DP[j][i] = DP[j-1][i];
            }
        }
    }
    
    cout << DP[N][K] << "\n";
    
   return 0;
}