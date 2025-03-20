#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int NArray[N]={};
	for(int i = 0; i < N; i++){
		cin >> NArray[i];
	}
	
	int start = 1, end = 2000000000, m = 0;
	long sum = 0;
	int result = 0;
	while(start <= end){
		sum = 0;
		m = (start+end)/2;
		for(int i = 0; i < N; i++){
			sum += NArray[i] <= m ? 0 : NArray[i]-m;
		}
		if(M <= sum){
			start = m+1;
			result = m;
		}else{
			end = m-1;
		}
	}
	
	cout << result << "\n";
	
	return 0;
}