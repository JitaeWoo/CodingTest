#include <iostream>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::list;

int main(void){
	int N = 0;
	cin >> N;
	
	list<int> NList;
	
	for(int i = N - 1; i >= 0 ; i--){
		NList.push_back(i+1);
	}
	
	for(int i = 0; i < N - 1; i++){
		NList.pop_back();
		NList.push_front(NList.back());
		NList.pop_back();
	}
	
	cout << NList.front() << endl;
	
	
	return 0;
}