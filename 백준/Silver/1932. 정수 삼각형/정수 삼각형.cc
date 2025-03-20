#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	
	int trian[n][n]={};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i+1; j++){
			cin >> trian[i][j];
		}
	}
	
	int DP[n][n]={};
	DP[0][0] = trian[0][0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i+1; j++){
			if(j != 0){
				DP[i][j] = trian[i][j] + (DP[i-1][j-1] > DP[i-1][j] ? DP[i-1][j-1] : DP[i-1][j]);
			}else{
				DP[i][j] = trian[i][j] + DP[i-1][j];
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(max < DP[n-1][i]){
			max = DP[n-1][i];
		}
	}
	
	cout << max << "\n";
	
	return 0;
}