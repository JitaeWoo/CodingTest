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
	
	int * NQ = new int[N];
	int head = 0, tail = 0;
	string option = "";
	
	for(int i = 0; i < N; i++){
		cin >> option;
		
		if(option.compare("push") == 0){
			int num = 0;
			cin >> num;
			NQ[tail++] = num;
		}else if(option.compare("pop") == 0){
			if(head < tail){
				cout << NQ[head++] << "\n";
			}else{
				cout << "-1\n";
			}
		}else if(option.compare("size") == 0){
			if(head < tail){
				cout << tail - head << "\n";
			}else{
				cout << "0\n";
			}
		}else if(option.compare("empty") == 0){
			if(head < tail){
				cout << "0\n";
			}else{
				cout << "1\n";
			}
		}else if(option.compare("front") == 0){
			if(head < tail){
				cout << NQ[head] << "\n";
			}else{
				cout << "-1\n";
			}
		}else if(option.compare("back") == 0){
			if(head < tail){
				cout << NQ[tail - 1] << "\n";
			}else{
				cout << "-1\n";
			}
		}
	}
	
	return 0;
}