#include <iostream>
#define ll long long
#define MAX 55

ll count_one(ll d[], ll x){
    ll result = x & 1;
    for(ll i = MAX-1; i > 0; i--){
        if(x & (1LL << i)){
            result += d[i-1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
        
    }
    
    return result;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    ll A = 0, B = 0;
    std::cin >> A >> B;
    
    ll d[MAX]={};
    d[0] = 1;
    for(ll i = 1; i < MAX; i++){
        d[i] = d[i-1] * 2 + (1LL << i);
    }
    
    
    std::cout << count_one(d, B) - count_one(d, A-1) << "\n";

    return 0;
}
