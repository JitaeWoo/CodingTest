#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void){
	int num1 = 0, num2 = 0;
	
	cin >> num1 >> num2;
	int N1 = num1, N2 = num2;
	int temp = 0;
	
	while(N1 % N2 != 0){
		N1 = N1 % N2;
		temp = N1;
		N1 = N2;
		N2 = temp;
	}
	
	cout << N2 << endl;
	cout << num1 * num2 / N2 << endl;
	
	return 0;
}