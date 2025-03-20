#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	string funtion = "", arr = "", result = "";
	int N = 0, startIdx = 0, endIdx = 0, op = 1;
	int NArray[100000]={};
	for(int i = 0; i < T; i++){
		cin >> funtion >> N >> arr;
		startIdx = 0;
		arr = arr.substr(1, arr.length()-2); // 숫자 배열 가공
		int p = 0, startPoint = 0;
		while((p = arr.find(",", startPoint)) != string::npos){
			NArray[startIdx++] = atoi(arr.substr(startPoint, p-startPoint).c_str());
			startPoint = p+1;
		}
		NArray[startIdx] = atoi(arr.substr(startPoint).c_str());
		
		p = 0, startPoint = 0;
		startIdx = 0;
		endIdx = N-1;
		op = 1;
		result = "";
		while((p = funtion.find("D", startPoint)) != string::npos){ // 명령어 가공
			if(funtion.substr(startPoint, p-startPoint).length() % 2 != 0){ // R이 2의 배수가 아니면
				op *= -1;
			}
			if(startIdx == endIdx+1){
				result = "error";
				break;
			}
			if(op == -1){ // D실행
				endIdx--;
			}else{
				startIdx++;
			}
			startPoint = p+1;
		}
		if(funtion.substr(startPoint).length() % 2 != 0){
			op *= -1;
		}
		
		if(result.compare("error") != 0){
			cout << "[";
			for(int j = op == 1 ? startIdx : endIdx; op == 1 ? j <= endIdx : j >= startIdx; j += op){
				cout << NArray[j];
				if(op == 1 ? j != endIdx : j != startIdx){
					cout << ",";
				}
			}
			cout << "]\n";
		}else{
			cout << result << "\n";
		}
	}
	
	return 0;
}