#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	char* stack = new char[1000];
	int idx = -1;
	bool isYes = true;
	string str = "";
	
	while(true){
		getline(cin, str);
		if(str[0] == '.'){
			break;
		}
		
		idx = -1;
		isYes = true;
		
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '('){
				stack[++idx] = '(';
			}else if(str[i] == '['){
				stack[++idx] = '[';
			}else if(str[i] == ')'){
				if(stack[idx--] != '('){
					isYes = false;
					break;
				}
			}else if(str[i] == ']'){
				if(stack[idx--] != '['){
					isYes = false;
					break;
				}
			}
		}
		
		if(isYes && idx == -1){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	
	return 0;
}