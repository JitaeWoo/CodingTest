#include <iostream>
#include <queue>
#include <list>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::list;

class Node{
public:
	int Vnum;
	int edge;
	
	Node(int Vnum, int edge){
		this->Vnum = Vnum;
		this->edge = edge;
	}
};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V = 0;
	cin >> V;
	
	int Vnum = 0, node = 0, edge = 0;
	list<Node> tree[V];
	list<Node>::iterator iter;
	Node* N;
	for(int i = 0; i < V; i++){
		cin >> Vnum >> node;
		while(node!=-1){
			cin >> edge;
			N = new Node(node-1, edge);
			tree[Vnum-1].push_front(*N);
			cin >> node;
		}
	}
	
	int check[V]={};
	queue<int> q;
	int distance = 0, result = 0, resultNode = 0, temp = 0;
	node = 0;
	distance = 0;
	check[node] = 1;
	while(true){
		for(iter = tree[node].begin(); iter != tree[node].end(); iter++){
			if(check[iter->Vnum] != 1){
				check[iter->Vnum] = 1;
				temp = distance + iter->edge;
				if(temp > result){
					result = temp;
					resultNode = iter->Vnum;
				}
				q.push(iter->Vnum);
				q.push(temp);
			}
		}
		
		if(q.empty()){
			break;
		}else{
			node = q.front(); q.pop();
			distance = q.front(); q.pop();
		}
	}
	
	for(int j = 0; j < V; j++){
		check[j] = 0;
	}
	
	node = resultNode;
	distance = 0;
	result = 0;
	check[node] = 1;
	while(true){
		for(iter = tree[node].begin(); iter != tree[node].end(); iter++){
			if(check[iter->Vnum] != 1){
				check[iter->Vnum] = 1;
				temp = distance + iter->edge;
				if(temp > result){
					result = temp;
					resultNode = iter->Vnum;
				}
				q.push(iter->Vnum);
				q.push(temp);
			}
		}
		
		if(q.empty()){
			break;
		}else{
			node = q.front(); q.pop();
			distance = q.front(); q.pop();
		}
	}
	
	cout << result << "\n";
	
	return 0;
}