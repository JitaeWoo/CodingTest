#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::sort;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int* NArray = new int[10000];
	int num = 0;
	
	for(int i = 0; i < 10000; i++){
		NArray[i] = 0;
	}
	
	for(int i = 0; i < N; i++){
		cin >> num;
		NArray[num - 1]++;
	}
	
	for(int i = 0; i < 10000; i++){
		num = NArray[i];
		for(int j = 0; j < num; j++){
			cout << i+1 << "\n";
		}
	}
	
	
	return 0;
}