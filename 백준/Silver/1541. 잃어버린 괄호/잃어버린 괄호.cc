#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::stoi;

int main(void){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	string str = "";
	cin >> str;
	
	int num[100]={};
	string minusStr[100]={};
	int idx = 0;
	string plusStr[100]={};
	int pIdx = 0;
	int curPosition = 0;
	int position = 0;
	while((position = str.find("-", curPosition)) != string::npos){
		int len = position - curPosition;
		minusStr[idx++] = str.substr(curPosition, len);
		curPosition = position+1;
	}
	minusStr[idx++] = str.substr(curPosition);
	
	int numIdx = 0;
	for(int i = 0; i < idx; i++){
		curPosition = 0;
		pIdx = 0;
		while((position = minusStr[i].find("+", curPosition)) != string::npos){
			int len = position - curPosition;
			plusStr[pIdx++] = minusStr[i].substr(curPosition, len);
			curPosition = position+1;
		}
		plusStr[pIdx++] = minusStr[i].substr(curPosition);
		
		for(int j = 0; j < pIdx; j++){
			num[numIdx] += stoi(plusStr[j]);
		}
		numIdx++;
	}
	
	int result = num[0];
	for(int i = 1; i < numIdx; i++){
		result -= num[i];
	}
	
	cout << result << "\n";
	
	return 0;
}