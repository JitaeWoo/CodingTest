#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::map;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	map<string,int> m;
	map<string,int>::iterator iter;
	int N = 0, result = 1;
	string str = "", temp = "";
	for(int i = 0; i < T; i++){
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> temp >> str;
			if(m.find(str) != m.end()){
				(m.find(str))->second++;
			}else{
				m.insert({str, 2});
			}
		}
		
		result = 1;
		for(iter = m.begin(); iter != m.end(); iter++){
			result *= iter->second;
		}
		result--;
		m.clear();
		
		cout << result << "\n";
	}
	
	return 0;
}