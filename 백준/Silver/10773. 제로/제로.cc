#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int K = 0;
	cin >> K;
	
	int* stack = new int[100000];
	int idx = -1;
	int num = 0;
	
	
	for(int i = 0; i < K; i++){
		cin >> num;
		if(num == 0){
			stack[idx--] = 0;
		}else{
			stack[++idx] = num;
		}
	}
	
	int sum = 0;
	while(idx > -1){
		sum += stack[idx--];
	}
	
	cout << sum << "\n";
	
	return 0;
}