#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	vector<int> tree[N+1];
	int start = 0, end = 0;
	for(int i = 0; i < N-1; i++){
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}
	
	queue<int> q;
	int result[N+1]={};
	int node = 0;
	q.push(1);
	while(!q.empty()){
		node = q.front();
		q.pop();
		
		for(int i : tree[node]){
			if(result[i] == 0){
				result[i] = node;
				q.push(i);
			}
		}
	}
	
	for(int i = 2; i <= N; i++){
		cout << result[i] << "\n";
	}
	
	
	
	return 0;
}