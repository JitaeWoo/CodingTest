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
	int N = 0, K = 0;
	cin >> N >> K;
	
	int check[200000]={};
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	int min = 1000000, count = 0;
	while(!q.empty()){
		int node = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(node == K){
			if(min > time){
				count = 1;
				min = time;
			}else{
				if(min == time){
					count++;
				}
			
			}
			continue;
		}
		
		check[node] = 1;
		
		if(node > 0 && check[node-1] != 1){
			q.push(make_pair(node-1, time+1));
		}
		if(node < 200000 && check[node+1] != 1){
			q.push(make_pair(node+1, time+1));
		}
		if(node*2 < 200000 && check[node*2] != 1){
			q.push(make_pair(node*2, time+1));
		}
	}
	
	cout << min << "\n";
	cout << count << "\n";
    
    return 0;
}