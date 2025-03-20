#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int * NArray = new int[N];
	for(int i = 0; i < N; i++){
		cin >> NArray[i];
	}
	
	int stackNum = 1, stackIdx = -1;
	int * NStack = new int[N];
	
	string result = "";
	int num = 0;
	for(int i = 0; i < N; i++){
		if(num < NArray[i]){
			for(int j = num; j < NArray[i]; j++){
				NStack[++stackIdx] = stackNum++;
				result += "+\n";
			}
			if(NArray[i] != NStack[stackIdx]){
				cout << "NO\n";
				return 0;
			}
			stackIdx--;
			result += "-\n";
			num = NArray[i];
		}else{
			if(NArray[i] != NStack[stackIdx]){
				cout << "NO\n";
				return 0;
			}
			stackIdx--;
			result += "-\n";
		}
	}
	
	cout << result;
	
	return 0;
}