#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, K = 0;
	cin >> N >> K;
	
	int coin[N]={};
	for(int i = 0; i < N; i++){
		cin >> coin[i];
	}
	
	int result = 0;
	for(int i = 0; i < N; i++){
		while(true){
			if(K >= coin[N-1-i]){
				K -= coin[N-1-i];
				result++;
				if(K == 0){
					cout << result << "\n";
					return 0;
				}
			}else{
				break;
			}
		}
	}
	
	return 0;
}