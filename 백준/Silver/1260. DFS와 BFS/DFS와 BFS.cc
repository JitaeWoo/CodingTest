#include <iostream>
#include <list>
using std::cout;
using std::cin;
using std::ios;
using std::list;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0, M = 0, V = 0;
	cin >> N >> M >> V;
	
	int start = 0, end = 0;
	list<int> graph[N];
	list<int>::iterator iter;
	for(int i = 0; i < M; i++){
		cin >> start >> end;
		graph[start-1].push_back(end);
		graph[end-1].push_back(start);
	}
	for(int i = 0; i < N; i++){
		graph[i].sort();
	}
	
	list<int> exploredNode;
	list<int>::iterator exIter;
	
	int stack[1000];
	int idx = -1;
	int node = V;
	cout << V << " ";
	exploredNode.push_back(V);
	bool isExplor = false;
	while(true){ // 깊이 탐색
		isExplor = true;
		for(iter = graph[node-1].begin(); iter != graph[node-1].end(); iter++){
			isExplor = false;
			for(exIter = exploredNode.begin(); exIter != exploredNode.end(); exIter++){
				if(*exIter == *iter){
					isExplor = true;
					break;
				}
			}
			if(!isExplor){
				stack[++idx] = node;
				node = *iter;
				exploredNode.push_back(node);
				cout << node << " ";
				break;
			}
		}
		if(isExplor){
			if(idx == -1){
				break;
			}else{
				node = stack[idx--];
			}
		}
	}
	cout << "\n";
	
	exploredNode.clear();
	list<int> queue;
	list<int>::iterator qIter;
	node = V;
	cout << node << " ";
	exploredNode.push_back(node);
	while(true){
		for(iter = graph[node-1].begin(); iter != graph[node-1].end(); iter++){
			isExplor = false;
			for(exIter = exploredNode.begin(); exIter != exploredNode.end(); exIter++){
				if(*iter == *exIter){
					isExplor = true;
					break;
				}
			}
			if(!isExplor){
				queue.push_back(*iter);
				cout << *iter << " ";
				exploredNode.push_back(*iter);
			}
		}
		if(queue.empty()){
			cout << "\n";
			break;
		}else{
			node = queue.front();
			queue.pop_front();
		}
	}
	
	return 0;
}