#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::atoi;
using std::unordered_map;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	string name = "";
	string poketmon[100001];
	unordered_map<string, int> pMap;
	for(int i = 1; i <= N; i++){
		cin >> name;
		poketmon[i] = name;
		pMap.insert({name, i});
	}
	
	int id = 0;
	for(int i = 0; i < M; i++){
		cin >> name;
		id = atoi(name.c_str());
		if(id == 0){
			cout << pMap.find(name)->second << "\n";
		}else{
			cout << poketmon[id] << "\n";
		}
	}
	
	return 0;
}