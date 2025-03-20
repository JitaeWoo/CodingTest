#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str1 = "", str2 = "";
    std::cin >> str1 >> str2;
    
    int LCS[str1.length()+1][str2.length()+1]={};
    
    int max = 0;
    int L_i = 0, L_j = 0;
    for(int i = 1; i <= str1.length(); i++){
        for(int j = 1; j <= str2.length(); j++){
            if(j == 3 && i == 2){
            }
            if(str1[i-1] == str2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
                if(max < LCS[i][j]){
                    max = LCS[i][j];
                    L_i = i;
                    L_j = j;
                }
            }else{
                LCS[i][j] = std::max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }
    
    char result[max]={};
    int max_idx = max-1;
    while(true){
        if(max_idx < 0){
            break;
        }
        
        if(LCS[L_i-1][L_j] != LCS[L_i][L_j] && LCS[L_i][L_j-1] != LCS[L_i][L_j]){
            result[max_idx--] = str1[L_i-1];
            L_i--; L_j--;
        }else if(LCS[L_i][L_j] == LCS[L_i-1][L_j]){
            L_i--;
        }else{
            L_j--;
        }
    }
    
    std::cout << max << "\n";
    for(int i = 0; i < max; i++){
        std::cout << result[i];
    }
    std::cout << "\n";
    
    return 0;
}