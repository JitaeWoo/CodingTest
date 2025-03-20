#include <iostream>
#include <string>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	cin >> T;
	
	int A = 0, B = 0, num = 0, temp = 0;
	string result = "", str = "";
	queue<string> qStr;
	queue<short> qNum;
	int check[10000]={};
	for(int i = 0; i < T; i++){
		cin >> A >> B;
		if(A == B){
			cout << "\n";
			continue;
		}
		
		result = "";
		num = A;
		str = "";
		check[A] = 1;
		
		while(true){ // BFS 탐색
			temp = 2*num % 10000;
			if(check[temp] != 1){
				if(temp != B){
					check[temp] = 1;
					qStr.push(str+"D");
					qNum.push(temp);
				}else{
					result = str+"D";
					break;
				}
			}
			
			temp = num == 0 ? 9999 : num-1;
			if(check[temp] != 1){
				if(temp != B){
					check[temp] = 1;
					qStr.push(str+"S");
					qNum.push(temp);
				}else{
					result = str+"S";
					break;
				}
			}
			
			temp = (num*10 + num/1000) % 10000;
			if(check[temp] != 1){
				if(temp != B){
					check[temp] = 1;
					qStr.push(str+"L");
					qNum.push(temp);
				}else{
					result = str+"L";
					break;
				}
			}
			
			temp = num/10 + (num % 10 * 1000);
			if(check[temp] != 1){
				if(temp != B){
					check[temp] = 1;
					qStr.push(str+"R");
					qNum.push(temp);
				}else{
					result = str+"R";
					break;
				}
			}
			
			str = qStr.front(); qStr.pop();
			num = qNum.front(); qNum.pop();
		}
		
		while(!qStr.empty()){ // 큐 비우기
			qStr.pop();
		}
		while(!qNum.empty()){
			qNum.pop();
		}
		for(int i = 0; i < 10000; i++){
			check[i] = 0;
		}
		cout << result << "\n";
	}
	
	return 0;
}