#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int * NArray = new int[N];
	for(int i = 0; i < N; i++){
		cin >> NArray[i];
	}
	
	sort(NArray, NArray+N);
	
	for(int i = 0; i < N; i++){
		cout << NArray[i] << "\n";
	}
	
	
	return 0;
}