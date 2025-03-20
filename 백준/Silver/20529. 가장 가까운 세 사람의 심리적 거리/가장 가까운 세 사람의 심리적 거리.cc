#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int diff(string per1, string per2){
	int d = 0;
	for(int i = 0; i < 4; i++){
		if(per1[i] != per2[i]){
			d++;
		}
	}
	
	return d;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int N = 0, min = 100, temp1 = 0, temp2 = 0;
	for(int i = 0; i < T; i++){
		cin >> N;
		
		string MBTI[N]={};
		for(int j = 0; j < N; j++){
			cin >> MBTI[j];
		}
		
		if(N > 32){
			cout << "0\n";
			continue;
		}
		
		min = 100;
		for(int j = 0; j < N; j++){
			for(int k = j+1; k < N; k++){
				temp1 = diff(MBTI[j], MBTI[k]);
				for(int h = k+1; h < N; h++){
					temp2 = diff(MBTI[k], MBTI[h]) + diff(MBTI[h], MBTI[j]);
					if(temp1+temp2 < min){
						min = temp1+temp2;
					}
				}
			}
		}
		
		cout << min << "\n";
	}
	
	return 0;
}