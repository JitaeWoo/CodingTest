#include <iostream>
#include <unordered_map>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::unordered_map;
using std::sort;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int NArray[N]={};
	int sortArray[N]={};
	int num = 0;
	for(int i = 0; i < N; i++){
		cin >> num;
		NArray[i] = num;
		sortArray[i] = num;
	}
	sort(sortArray, sortArray+N);
	
	unordered_map<int, int> map;
	int point = 0;
	map.insert({sortArray[0], point++});
	for(int i = 1; i < N; i++){
		if(sortArray[i-1] != sortArray[i]){
			map.insert({sortArray[i], point++});
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << (map.find(NArray[i]))->second << " ";
	}
	cout << "\n";
	
	return 0;
}