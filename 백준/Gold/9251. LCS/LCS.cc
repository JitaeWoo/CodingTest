#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str1 = "", str2 = "";
	cin >> str1 >> str2;
	int LCS[1001][1001]={};
	
	for(int i = 1; i <= str1.length(); i++){
		for(int j = 1; j <= str2.length(); j++){
			if(str1[i-1] == str2[j-1]){
				LCS[i][j] = LCS[i-1][j-1]+1;
			}else{
				LCS[i][j] = LCS[i-1][j] > LCS[i][j-1] ? LCS[i-1][j] : LCS[i][j-1];
			}
		}
	}
	
	cout << LCS[str1.length()][str2.length()] << "\n";
	
	return 0;
}