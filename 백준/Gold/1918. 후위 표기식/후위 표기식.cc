#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str = "";
	cin >> str;
	
	string result = "";
	char stack[100]={};
	int idx = -1;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '*' || str[i] == '/'){
			if(str[i+1] == '('){
				stack[++idx] = str[i];
			}else{
				while(stack[idx] != '(' && stack[idx] != '+' && stack[idx] != '-' && idx != -1){
					result += stack[idx--];
				}
				result += str[i+1];
				result += str[i];
				i++;
			}
		}else if(str[i] == '+' || str[i] == '-'){
			while(stack[idx] != '(' && idx != -1){
				result += stack[idx--];
			}
			stack[++idx] = str[i];
		}else if(str[i] == ')'){
			while(stack[idx] != '('){
				result += stack[idx--];
			}
			idx--;
		}else if(str[i] == '('){
			stack[++idx] = '(';
		}else{
			result += str[i];
		}
	}
	
	while(idx != -1){
		result += stack[idx--];
	}
	
	cout << result << "\n";
	
	return 0;
}