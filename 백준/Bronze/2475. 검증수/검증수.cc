#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void){
	int num1=0, num2=0, num3=0, num4=0, num5=0;
	int result=0;
	
	cin>>num1>>num2>>num3>>num4>>num5;
	result = (num1*num1 + num2*num2 + num3*num3 + num4*num4 + num5*num5) % 10;
	
	cout<<result<<endl;
}