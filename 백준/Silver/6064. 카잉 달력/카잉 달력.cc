#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int M = 0, N = 0, x = 0, y = 0, result = 0;
	for(int i = 0; i < T; i++){
		cin >> M >> N >> x >> y;
		if(y == N){
			y = 0;
		}
		int num = N*M, temp = 0, a = M, b = N;
		while(a % b != 0){ // 최소공약수 계산
			temp = b;
			b = a % b;
			a = temp;
		}
		num /= b; // 최소공배수
		
		int result = -1;
		for(int i = x; i <= num; i+=M){
			if(i % N == y){
				result = i;
				break;
			}
		}
		
		cout << result << "\n";
	}
	
	return 0;
}