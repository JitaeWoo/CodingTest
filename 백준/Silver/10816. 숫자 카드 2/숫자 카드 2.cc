#include <iostream>
#include <map>
using std::cout;
using std::cin;
using std::ios;
using std::map;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	map<int, int> NMap;
	int temp = 0;
	for(int i = 0; i < N; i++){
		cin >> temp;
		NMap[temp]++;
	}
	
	int M = 0;
	cin >> M;
	
	int * MArray = new int[M];
	for(int i = 0; i < M; i++){
		cin >> MArray[i];
	}
	
	int num = 0;
	for(int i = 0; i < M; i++){
		if(NMap.find(MArray[i]) != NMap.end())
			cout << NMap.find(MArray[i])->second << " ";
		else
			cout << "0 ";
	}
	
	return 0;
}