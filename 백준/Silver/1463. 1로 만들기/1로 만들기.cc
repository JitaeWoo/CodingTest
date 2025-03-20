#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int Nto1(int N){
	static int result[1000001]= {0, 0, 1, 1};
	int min = 1000000, temp = 0;
	if(result[N] == 0 && N > 1){ // 아직 값이 없다면
		if(N % 3 == 0){
			temp = 1+Nto1(N/3);
			if(min > temp){
				min = temp;
			}
		}
		if(N % 2 == 0){
			temp = 1+Nto1(N/2);
			if(min > temp){
				min = temp;
			}
		}
		
		temp = 1+Nto1(N-1);
		if(min > temp){
			min = temp;
		}
		
		result[N] = min;
		return min;
		
	}else{ // 이미 값이 있다면
		return result[N];
	}
	
}

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	cout << Nto1(N) << "\n";
	
	return 0;
}