#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void){
	while(true){
		string str = "";
		
		cin >> str;
		
		if(str[0] == '0')
			break;
		
		bool isP = true;
		int first = 0;
		int last = str.length() - 1;
		while(first < last){
			if(str[first] != str[last])
				isP = false;
			
			first++;
			last--;
		}
		
		if(isP){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	
	return 0;
}