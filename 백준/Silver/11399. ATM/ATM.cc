#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::sort;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int P[N];
	for(int i = 0; i < N; i++){
		cin >> P[i];
	}
	
	sort(P, P+N);
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			sum += P[j];
		}
	}
	
	cout << sum << "\n";
	
	return 0;
}