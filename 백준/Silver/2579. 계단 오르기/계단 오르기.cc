#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int stairs[301];
	for(int i = 1; i <= N; i++){
		cin >> stairs[i];
	}
	
	int DP[301]={};
	DP[1] = stairs[1];
	DP[2] = stairs[1] + stairs[2];
	int case1 = 0, case2 = 0;
	for(int i = 3; i <= N; i++){
		case1 = DP[i-3] + stairs[i-1] + stairs[i];
		case2 = DP[i-2] + stairs[i];
		DP[i] = case1 > case2 ? case1 : case2;
	}
	
	cout << DP[N] << "\n";
	
	return 0;
}