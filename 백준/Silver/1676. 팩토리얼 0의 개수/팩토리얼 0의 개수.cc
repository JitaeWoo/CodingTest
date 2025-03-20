#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int num = 0;
	int num2 = 0;
	int num5 = 0;
	for(int i = 2; i <= N; i++){
		num = i;
		while(num % 2 == 0){
			num2++;
			num /= 2;
		}
		num = i;
		while(num % 5 == 0){
			num5++;
			num /= 5;
		}
		
	}
	
	int result = num2 < num5 ? num2 : num5;
	
	cout << result << "\n";
	
	return 0;
}