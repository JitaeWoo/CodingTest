#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int result = 0;
	for(int i = 1; i < 225; i++){
		if(i*i == N){
			cout << "1\n";
			return 0;
		}
	}
	for(int i = 1; i < 225; i++){
		for(int j = 1; j < 225; j++){
			if(i*i + j*j == N){
				cout << "2\n";
				return 0;
			}
		}
	}
	for(int i = 1; i < 225; i++){
		for(int j = 1; j < 225; j++){
			for(int k = 1; k < 225; k++){
				if(i*i + j*j + k*k == N){
					cout << "3\n";
					return 0;
				}
			}
		}
	}
	
	cout << "4\n";
	return 0;
}