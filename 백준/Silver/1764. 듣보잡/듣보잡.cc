#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::sort;
using std::unordered_map;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	unordered_map<string, int> NMap;
	string str = "";
	for(int i = 0; i < N; i++){
		cin >> str;
		NMap.insert({str, i});
	}
	
	unordered_map<string, int> MMap;
	for(int i = 0; i < M; i++){
		cin >> str;
		MMap.insert({str, i});
	}
	
	string result[50000]={};
	int idx = 0;
	for(auto iter = NMap.begin(); iter != NMap.end(); iter++){
		if(MMap.find(iter->first) != MMap.end()){
			result[idx++] = iter->first;
		}
	}
	
	sort(result, result+idx);
	cout << idx << "\n";
	for(int i = 0; i < idx; i++){
		cout << result[i] << "\n";
	}
	
	return 0;
}