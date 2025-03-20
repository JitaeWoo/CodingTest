#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	string S = "";
	cin >> N >> M >> S;
	
	int i = 0, Pn = 0, result = 0;
	bool on = false;
	while(i < S.length()){
		if(!on){
			if(S[i] == 'I'){
				on = true;
			}
			i++;
		}else{
			if(i < S.length()-1){
				if(S[i] == 'O' && S[i+1] == 'I'){
					Pn++;
					i += 2;
				}else{
					on = false;
					if(Pn >= N){
						result += Pn - N + 1;
					}
					Pn = 0;
				}
			}else{
				break;
			}
		}
	}
	
	if(Pn >= N){
		result += Pn - N + 1;
	}
	
	
	cout << result << "\n";
	
	return 0;
}