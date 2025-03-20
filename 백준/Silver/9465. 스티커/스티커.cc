#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int n = 0, two = 2;
		cin >> n;
		
		int sticker[two][n];
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < n; k++){
				cin >> sticker[j][k];
			}
		}
		
		int DP[two][n];
		DP[0][0] = sticker[0][0];
		DP[0][1] = sticker[0][1] + sticker[1][0];
		DP[1][0] = sticker[1][0];
		DP[1][1] = sticker[1][1] + sticker[0][0];
		
		for(int j = 2; j < n; j++){
			DP[0][j] = sticker[0][j] + (DP[1][j-1] > DP[1][j-2] ? DP[1][j-1] : DP[1][j-2]);
			DP[1][j] = sticker[1][j] + (DP[0][j-1] > DP[0][j-2] ? DP[0][j-1] : DP[0][j-2]);
		}
		
		cout << (DP[0][n-1] > DP[1][n-1] ? DP[0][n-1] : DP[1][n-1]) << "\n";
	}
	
	return 0;
}