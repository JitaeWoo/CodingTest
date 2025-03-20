#include <iostream>
using std::cout;
using std::cin;
using std::ios;

class Node{
public:
	int num;
	Node* left;
	Node* right;
	
	Node(int num){
		this->num = num;
		left = NULL;
		right = NULL;
	}
};

void makeTree(int num, Node* node){
	if(node->num < num){
		if(node->right == NULL){
			node->right = new Node(num);
		}else{
			makeTree(num, node->right);
		}
	}else{
		if(node->left == NULL){
			node->left = new Node(num);
		}else{
			makeTree(num, node->left);
		}
	}
}

void postorder(Node* node){
	if(node->left != NULL){
		postorder(node->left);
	}
	if(node->right != NULL){
		postorder(node->right);
	}
	cout << node->num << "\n";
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	Node* root = NULL;
	while(true){
		cin >> n;
		if(cin.eof()){
			break;
		}
		if(root == NULL){
			root = new Node(n);
		}else{
			makeTree(n, root);
		}
	}
	
	postorder(root);
	
	return 0;
}