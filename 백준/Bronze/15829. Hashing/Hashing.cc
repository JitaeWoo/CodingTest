#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int L = 0;
	string str = "";
	cin >> L >> str;
	
	long long result = 0;
	long long sum = 0;
	for(int i = 0; i < L; i++){
		result = str[i] - 96;
		
		for(int j = 0; j < i; j++){
			result *= 31;
			result %= 1234567891;
		}
		sum += result;
		sum %= 1234567891;
	}
	
	cout << sum << "\n";
	
	return 0;
}