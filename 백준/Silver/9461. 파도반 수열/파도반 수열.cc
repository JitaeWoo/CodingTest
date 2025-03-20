#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	long long P[101]={};
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	int num = 0, idx = 4;
	for(int i = 0; i < T; i++){
		cin >> num;
		if(num > idx){
			while(idx < num){
				P[idx+1] = P[idx] + P[idx-4];
				idx++;
			}
		}
		cout << P[num] << "\n";
	}
	
	return 0;
}