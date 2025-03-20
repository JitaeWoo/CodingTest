#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0, K = 0;
	cin >> N >> K;
	
	int result = 1;
	for(int i = 0; i < K; i++){
		result *= N - i;
	}
	
	for(int i = 2; i <= K; i++){
		result /= i;
	}
	
	cout << result << "\n";
	
	return 0;
}