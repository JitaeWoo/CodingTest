#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A = 0, B = 0, C = 0;
    std::cin >> A >> B >> C;
    
    int d = 1, b = B;
    while(b / 10 != 0){
        b /= 10;
        d++;
    }
    
    std::cout << A + B - C << "\n";
    
    for(int i = 0; i < d; i++){
        A *= 10;
    }
    
    std::cout << A + B - C << "\n";

    return 0;
}