#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::map;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	map<string, string> m;
	string domain = "", passwd = "";
	for(int i = 0; i < N; i++){
		cin >> domain >> passwd;
		m.insert({domain, passwd});
	}
	
	for(int i = 0; i < M; i++){
		cin >> domain;
		cout << m.find(domain)->second << "\n";
	}
	
	return 0;
}