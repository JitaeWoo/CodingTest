#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::pow;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M = 0;
	cin >> M;
	
	string option = "";
	int num = 0;
	int set = 0;
	for(int i = 0; i < M; i++){
		cin >> option;
		if(option.compare("empty") != 0 && option.compare("all") != 0){
			cin >> num;
		}
		
		if(option.compare("add") == 0){
			set |= (1 << num-1);
		}else if(option.compare("remove") == 0){
			set &= ~(1 << num-1);
		}else if(option.compare("check") == 0){
			if((set & (1 << num-1)) != 0){
				cout << "1\n";
			}else{
				cout << "0\n";
			}
		}else if(option.compare("toggle") == 0){
			set ^= (1 << num-1);
		}else if(option.compare("all") == 0){
			set = (1 << 20)-1;
		}else if(option.compare("empty") == 0){
			set = 0;
		}
	}
	
	return 0;
}