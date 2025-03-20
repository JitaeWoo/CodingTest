#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

class Node{
public:
	char left;
	char right;
	
	Node(char left, char right){
		this->left = left;
		this->right = right;
	}
};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	Node* tree[N]={};
	char start, left, right;
	for(int i = 0; i < N; i++){
		cin >> start >> left >> right;
		tree[start-'A'] = new Node(left, right);
	}
	
	int check[26]={}, stack[N]={};
	int idx = -1;
	int node = 0;
	string str1 = "A", str2 = "", str3 = "";
	char temp;
	while(true){
		temp = tree[node]->left;
		if(temp != '.' && check[temp-'A'] != 1){
			check[temp-'A'] = 1;
			stack[++idx] = node;
			node = temp - 'A';
			str1 += (char)(node+65); // 전위 순회
			continue;
		}
		
		str2 += (char)(node+65); // 중위 순회
		
		temp = tree[node]->right;
		if(temp != '.' && check[temp-'A'] != 1){
			check[temp-'A'] = 1;
			node = temp - 'A';
			str1 += (char)(node+65); // 전위 순회
			continue;
		}
		
		
		if(idx != -1){
			node = stack[idx--];
		}else{
			break;
		}
	}
	
	for(int i = 0; i < N; i++){
		check[i] = 0;
	}
	node = 0;
	while(true){
		temp = tree[node]->left;
		if(temp != '.' && check[temp-'A'] != 1){
			check[temp-'A'] = 1;
			stack[++idx] = node;
			node = temp - 'A';
			continue;
		}
		
		temp = tree[node]->right;
		if(temp != '.' && check[temp-'A'] != 1){
			check[temp-'A'] = 1;
			stack[++idx] = node;
			node = temp - 'A';
			continue;
		}
		
		str3 += (char)(node+65); // 후위 순회
		
		if(idx != -1){
			node = stack[idx--];
		}else{
			break;
		}
	}
	
	cout  << str1 << "\n";
	cout  << str2 << "\n";
	cout  << str3 << "\n";
	
	return 0;
}