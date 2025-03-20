#include <iostream>
#include <cmath>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::round;
using std::sort;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	if(N == 0){
		cout << "0\n";
		return 0;
	}
	
	int* NArray = new int[N];
	for(int i = 0; i < N; i++){
		cin >> NArray[i];
	}
	sort(NArray, NArray+N);
	
	int start = 0, end = 0;
	start = round(N * 0.15);
	end = N - start;
	
	int sum = 0;
	for(int i = start; i < end; i++){
		sum += NArray[i];
	}
	
	int result = round((float)sum / (N - 2*start));
	
	cout << result << "\n";
	
	return 0;
}