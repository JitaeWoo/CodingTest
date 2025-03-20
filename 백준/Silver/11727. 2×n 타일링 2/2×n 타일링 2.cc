#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	long long P[1000]={};
	P[0] = 1;
	P[1] = 3;
	for(int i = 2; i < N; i++){
		P[i] = (P[i-2]*2 + P[i-1])%10007;
	}
	
	cout << P[N-1] << "\n";
	
	return 0;
}