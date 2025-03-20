#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int * NStack = new int[N];
	int idx = -1;
	string option = "";
	
	for(int i = 0; i < N; i++){
		cin >> option;
		if(option.compare("push") == 0){
			int num = 0;
			cin >> num;
			NStack[++idx] = num;
		}else if(option.compare("pop") == 0){
			if(idx < 0){
				cout << "-1\n";				
			}
			else{
				cout << NStack[idx--] << "\n";				
			}
		}else if(option.compare("size") == 0){
			if(idx < 0){
				cout << "0\n";				
			}
			else{
				cout << idx + 1 << "\n";				
			}
		}else if(option.compare("empty") == 0){
			if(idx < 0){
				cout << "1\n";				
			}
			else{
				cout << "0\n";				
			}
		}else if(option.compare("top") == 0){
			if(idx < 0){
				cout << "-1\n";				
			}
			else{
				cout << NStack[idx] << "\n";				
			}
		}
	}
	
	return 0;
}