#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pow;

int main(void){
	int K = 0, N = 0;
	
	cin>>K>>N;
	
	int* KArray = new int[K];
	for(int i = 0; i < K; i++){
		cin>>KArray[i];
	}
	
	long long left = 1;
	long long right = pow(2, 31) - 1;
	long long m = 0;
	int result = 0;
	int a = 0;
	
	while(left <= right){
		m = (left + right) / 2;
		result = 0;
		for(int i = 0; i < K; i++){
			result += KArray[i] / m;
		}
		
		if(result >= N){
			a = m;
			left = m + 1;
		}else{
			right = m - 1;
		}
	}
	
	cout<<a<<endl;
	
	return 0;
}