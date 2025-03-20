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
	cin>>N;
	int * NArray = new int[N];
	for(int i = 0; i < N; i++){
		cin>>NArray[i];
	}
	int M = 0;
	cin>>M;
	int * MArray = new int[M];
	for(int i = 0; i < M; i++){
		cin>>MArray[i];
	}
	sort(NArray, NArray+N); // 정렬
	
	int m = 0;
	int left = 0;
	int right = N - 1;
	bool isSame = false;
	
	for(int i = 0; i < M; i++){ // 이분탐색
		isSame = false;
		left = 0;
		right = N - 1;
		while(left <= right){
			m = (left + right) / 2;
			if(NArray[m] > MArray[i]){
				right = m - 1;
			}else if(NArray[m] < MArray[i]){
				left = m + 1;
			}else{
				cout<<"1\n";
				isSame = true;
				break;
			}
		}
		
		if(!isSame){
			cout<<"0\n";
		}
	}
	
	return 0;
}