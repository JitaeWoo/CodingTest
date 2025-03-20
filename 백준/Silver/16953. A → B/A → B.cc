#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::pair;
using std::make_pair;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int A = 0, B = 0;
	cin >> A >> B;
	
	queue<long long> q;
	q.push(A);
	q.push(-1);
	int isMake = false, level = 0;
	while(!q.empty()){
		long long num = q.front();
		q.pop();
		
		if(num == B){
			isMake = true;
			break;
		}
		
		if(num*2 <= B){
			q.push(num*2);
		}
		if(num*10 + 1 <= B){
			q.push(num*10 + 1);
		}
		
		if(q.front() == -1){
			q.pop();
			level++;
			if(q.empty()){
				break;
			}
			q.push(-1);
		}
	}
	
	if(isMake){
		cout << level+1 << "\n";
	}else{
		cout << -1 << "\n";
	}
	
    return 0;
}