#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void){
	int N = 0; 
	cin >> N;
	
	string temp = "";
	string result = "YES";
	int left = 0;
	
	for(int i = 0; i < N; i++){
		cin >> temp;
		result = "YES";
		left = 0;
		for(int j = 0; j < temp.length(); j++){
			if(temp[j] == '('){
				left++;
			}else{
				left--;
				if(left < 0){
					break;
				}
			}
		}
		
		if(left != 0){
			result = "NO";
		}
		
		cout << result << endl;
	}
	
	return 0;
}