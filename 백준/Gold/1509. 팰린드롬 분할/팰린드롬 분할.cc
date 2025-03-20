#include <iostream>
#include <string>

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::string str = "";
	std::cin >> str;
	
	bool DP[str.length()+1][str.length()+1]={};
	for(int i = 1; i <= str.length(); i++){
		DP[i][i] = true;
		if(i != str.length() && str[i-1] == str[i]){
			DP[i][i+1] = true;
		}
	}
	
	for(int i = 2; i <= str.length(); i++){
		for(int j = 1; j+i <= str.length(); j++){
			if(str[j-1] == str[j-1+i] && DP[j+1][j+i-1]){
				DP[j][j+i] = true;
			}
		}
	}
	
	int result[str.length()+1]={};
	for(int i = 2; i <= str.length(); i++){
		result[i] = 5000;
	}
	result[1] = 1;
	for(int i = 2; i <= str.length(); i++){
		for(int j = 1; j <= i; j++){
			if(DP[j][i] == true){
				if(result[i] > result[j-1]+1){
					result[i] = result[j-1]+1;
				}
			}
		}
	}
	
	std::cout << result[str.length()] << "\n";
	
    return 0;
}