#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int NArray[N]={};
	NArray[0] = 1;
	NArray[1] = 2;
	
	for(int i = 2; i < N; i++){
		NArray[i] = (NArray[i-1]+NArray[i-2]) % 10007;
	}
	
	cout << NArray[N-1] << "\n";
	
	return 0;
}