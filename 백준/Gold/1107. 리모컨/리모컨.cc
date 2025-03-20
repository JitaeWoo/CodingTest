#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int MArray[M];
	for(int i = 0; i < M; i++){
		cin >> MArray[i];
	}
	
	int num = 0, temp = 0, diff = 500000, result = 0;
	bool isFail = false;
	for(int i = 0; i <= 1000000; i++){
		isFail = false;
		num = i;
		int len = 0;
		if(num != 0){
			int n = num;
			while(n != 0){
				len++;
				n /= 10;
			}
		}else{
			len = 1;
		}
		
		for(int j = 0; j < len; j++){	
			temp = num % 10;
			for(int k = 0; k < M; k++){
				if(temp == MArray[k]){
					isFail = true;
					break;
				}
			}
			if(isFail){
				break;
			}else{
				num /= 10;
			}
		}
		if(isFail){
			continue;
		}else{
			temp = N-i;
			if(temp < 0){
				temp *= -1;
			}
			if(diff > temp){
				diff = temp;
				result = i;
			}
		}
	}
	
	int result1 = diff;
	if(result != 0){
		while(result != 0){
			result1++;
			result /= 10;
		}
	}else{
		result1++;
	}
	
	temp = N - 100;
	if(temp < 0){
		temp *= -1;
	}
	int result2 = temp;
	
	cout << (result1 < result2 ? result1 : result2) << "\n";
	
	return 0;
}