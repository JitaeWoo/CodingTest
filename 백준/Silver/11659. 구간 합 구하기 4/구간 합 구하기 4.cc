#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int NArray[N+1];
	for(int i = 1; i <= N; i++){
		cin >> NArray[i];
	}
	
	
	int sumArray[N+1]={};
	int sum = 0;
	for(int i = 1; i <= N; i++){
		sum += NArray[i];
		sumArray[i] = sum;
	}
	
	int start = 0, end = 0;
	for(int i = 0; i < M; i++){
		sum = 0;
		cin >> start >> end;
		
		sum = sumArray[end] - sumArray[start-1];
		cout << sum << "\n";
	}
	
	return 0;
}