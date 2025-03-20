#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, K = 0;
	cin >> N >> K;
	if(N == K){
		cout << "0\n";
		return 0;
	}
	
	int node[1000000]={};
	int level = 1;
	queue<int> queue;
	queue.push(-1);
	while(true){
		if(N > 0 && node[N-1] == 0){
			if(N-1 == K){
				break;
			}
			queue.push(N-1);
			node[N-1] = 1;
		}
		if(N<100000 && node[N+1] == 0){
			if(N+1 == K){
				break;
			}
			queue.push(N+1);
			node[N+1] = 1;
		}
		if(N<100000 && node[N*2] == 0){
			if(N*2 == K){
				break;
			}
			queue.push(N*2);
			node[N*2] = 1;
		}
		
		if(queue.front() == -1){
			queue.pop();
			level++;
			queue.push(-1);
		}
		N = queue.front();
		queue.pop();
	}
	
	cout << level << "\n";
	
	return 0;
}