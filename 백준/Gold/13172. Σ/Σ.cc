#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::pair;
using std::make_pair;

int GCD(int N, int S){
    int temp = 0;
    while(N % S != 0){
        N %= S;
        temp = N;
        N = S;
        S = temp;
    }
    
    return S;
}

long long power(long long num, long long b){
    if(b <= 1){
        return num;
    }else{
        long long temp = power(num, b/2);
        if(b % 2 == 0){
            return temp * temp % 1000000007;
        }else{
            return ((temp * temp) % 1000000007) * num % 1000000007;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M = 0;
    cin >> M;
    
    vector<pair<int, int>> dices;
    long long N = 0, S = 0;
    for(int i = 0; i < M; i++){
        cin >> N >> S;
        dices.push_back(make_pair(N, S));
    }
    long long result = 0;
    for(pair<int, int> dice : dices){
        N = dice.first;
        S = dice.second;
        
        int gcd = GCD(N, S);
        N /= gcd;
        S /= gcd;
        result = (result + (S * power(N, 1000000005) % 1000000007)) % 1000000007;
    }
    
    cout << result << "\n";
    
    return 0;
}