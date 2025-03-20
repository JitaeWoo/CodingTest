#include <iostream>
#include <string>
#include <list>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::list;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	list<int> NDeque;
	string option = "";
	int num = 0;
	for(int i = 0; i < N; i++){
		cin >> option;
		
		if(option.compare("push_front") == 0){
			cin >> num;
			NDeque.push_front(num);
		}else if(option.compare("push_back") == 0){
			cin >> num;
			NDeque.push_back(num);
		}else if(option.compare("pop_front") == 0){
			if(NDeque.size() > 0){
				cout << NDeque.front() << "\n";
				NDeque.pop_front();
			}else{
				cout << "-1\n";
			}
		}else if(option.compare("pop_back") == 0){
			if(NDeque.size() > 0){
				cout << NDeque.back() << "\n";
				NDeque.pop_back();
			}else{
				cout << "-1\n";
			}
		}else if(option.compare("size") == 0){
			cout << NDeque.size() << "\n";
		}else if(option.compare("empty") == 0){
			if(NDeque.size() > 0){
				cout << "0\n";
			}else{
				cout << "1\n";
			}
		}else if(option.compare("front") == 0){
			if(NDeque.size() > 0){
				cout << NDeque.front() << "\n";
			}else{
				cout << "-1\n";
			}
		}else if(option.compare("back") == 0){
			if(NDeque.size() > 0){
				cout << NDeque.back() << "\n";
			}else{
				cout << "-1\n";
			}
		}
	}
	return 0;
}