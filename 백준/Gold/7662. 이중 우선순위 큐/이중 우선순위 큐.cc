#include <iostream>
#include <set>
using std::cout;
using std::cin;
using std::ios;
using std::multiset;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int k = 0;
	multiset<int> s;
	for(int i = 0; i < T; i++){
		cin >> k;
		char op = 0;
		int num = 0;
		s.clear();
		for(int j = 0; j < k; j++){
			cin >> op >> num;
			if(op == 'I'){ // 삽입 연산
				s.insert(num);
			}else{ // 삭제 연산
				if(!s.empty()){ // 큐가 비어있지 않다면
					if(num == 1){
						s.erase(--(s.end()));
					}else{
						s.erase(s.begin());
					}
				}
			}
		}
		
		if(s.empty()){
			cout << "EMPTY\n";
		}else{
			cout << *(--(s.end())) << " " << *(s.begin()) << "\n";
		}
	}
	
	return 0;
}