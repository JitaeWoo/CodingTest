#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int fibonacci(int n){
	if(n==-1){
		return 1;
	}else if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		int num1 = 0, num2 = 1, temp = 0;
		for(int i = 1; i < n; i++){
			temp = num2;
			num2 = num1 + num2;
			num1 = temp;
		}
		
		return num2;
	}
}


int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int* NArray = new int[T];
	for(int i = 0; i < T; i++){
		cin >> NArray[i];
	}
	
	int num0 = 0, num1 = 0;
	for(int i = 0; i < T; i++){
		num0 = fibonacci(NArray[i]-1);
		num1 = fibonacci(NArray[i]);
		cout << num0 << " " << num1 << "\n";
	}
	
	return 0;
}