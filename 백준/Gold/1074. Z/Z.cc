#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::ios;
using std::pow;

int Z(int c, int r, int N){
	int len = pow(2, N)-1;
	int result = 0;
	
	while(len != 0){
		if(len / 2 >= c && len / 2 >= r){
			len /= 2;
		}else if(len / 2 < c && len / 2 >= r){
			result += pow(len+1, 2)/4;
			len /= 2;
			c -= len + 1;
		}else if(len / 2 >= c && len / 2 < r){
			result += pow(len+1, 2)/2;
			len /= 2;
			r -= len + 1;
		}else if(len / 2 < c && len / 2 < r){
			result += pow(len+1, 2)*0.75;
			len /= 2;
			c -= len + 1;
			r -= len + 1;
		}
	}
	
	return result;
}

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0, r = 0, c = 0;
	cin >> N >> r >> c;
	
	int result = Z(c, r, N);
	
	cout << result << "\n";
	
	return 0;
}