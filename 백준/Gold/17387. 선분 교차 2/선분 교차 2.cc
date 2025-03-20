#include <iostream>
#include <algorithm>
#define ll long long
#define pll std::pair<ll,ll>

int CCW(pll p1, pll p2, pll p3){
    pll v1(p2.first - p1.first, p2.second - p1.second);
    pll v2(p3.first - p1.first, p3.second - p1.second);
    
    ll z = v1.first * v2.second - v1.second * v2.first;
    
    if(z > 0){
        return 1;
    }else if(z < 0){
        return -1;
    }else{
        return 0;
    }
}

bool f1(std::pair<pll, pll> l1, std::pair<pll, pll> l2){
    pll p1 = l1.first;
    pll p2 = l1.second;
    pll p3 = l2.first;
    pll p4 = l2.second;
    
    int CCW1 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    int CCW2 = CCW(p3, p4, p1) * CCW(p3, p4, p2);
    
    if(CCW1 == 0 && CCW2 == 0){
        if(p1 > p2) std::swap(p1, p2);
        if(p3 > p4) std::swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    
    return CCW1 <= 0 && CCW2 <= 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::pair<pll, pll> L1, L2;
    std::cin >> L1.first.first >> L1.first.second >> L1.second.first >> L1.second.second;
    std::cin >> L2.first.first >> L2.first.second >> L2.second.first >> L2.second.second;
    
    if(f1(L1, L2)){
        std::cout << "1\n";
    }else{
        std::cout << "0\n";
    }
    
    
    return 0;
}