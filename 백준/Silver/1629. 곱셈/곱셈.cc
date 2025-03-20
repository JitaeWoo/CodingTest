#include <iostream>
using std::cout;
using std::cin;
using std::ios;

long long f1(long long A, long long B, long long C){
	if(B == 1){
		return A%C;
	}else if(B == 2){
		return (A%C)*(A%C)%C;
	}else{
		long long result = f1(A, B/2, C);
		if(B % 2 == 0){
			return result * result % C;
		}else{
			return (result*result%C)*A%C;
		}
	}
		
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A = 0, B = 0, C = 0;
	cin >> A >> B >> C;
	
	long long result = f1(A, B, C);
	
	cout << result << "\n";
	
	return 0;
}