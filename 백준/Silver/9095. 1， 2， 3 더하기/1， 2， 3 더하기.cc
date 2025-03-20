#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

void f1(int* result, int n){
	if(n < 0){
		return;
	}else if(n == 0){
		(*result)++;
	}else{
		f1(result, n-1);
		f1(result, n-2);
		f1(result, n-3);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int n = 0;
	for(int i = 0; i < T; i++){
		cin >> n;
		int result = 0;
		f1(&result, n);
		cout << result << "\n";
	}
	
	return 0;
}