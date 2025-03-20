#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int prise[N+1][3];
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 3; j++){
			cin >> prise[i][j];
		}
	}
	
	int P[N+1][3]={};
	for(int i = 1; i <= N; i++){
		P[i][0] = prise[i][0] + (P[i-1][1] < P[i-1][2] ? P[i-1][1] : P[i-1][2]);
		P[i][1] = prise[i][1] + (P[i-1][0] < P[i-1][2] ? P[i-1][0] : P[i-1][2]);
		P[i][2] = prise[i][2] + (P[i-1][0] < P[i-1][1] ? P[i-1][0] : P[i-1][1]);
	}
	
	int min = P[N][0];
	for(int i = 1; i < 3; i++){
		if(min > P[N][i]){
			min = P[N][i];
		}
	}
	
	cout << min << "\n";
	
	return 0;
}