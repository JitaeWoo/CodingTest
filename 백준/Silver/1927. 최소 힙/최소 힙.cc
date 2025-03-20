#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int heap[1000001]={};
	for(int i = 1; i < 1000001; i++){
		heap[i] = 2147483648-1; // 2의 31승 - 1
	}
	int idx = 0, op = 0;
	for(int i = 0; i < N; i++){
		cin >> op;
		
		if(op == 0){
			if(idx == 0){
				cout << "0\n";
			}else{
				cout << heap[1] << "\n";
				heap[1] = heap[idx];
				heap[idx--] = 2147483648-1;
				int node = 1, temp = 0;
				while(true){
					if(heap[node*2] < heap[node*2+1]){
						if(heap[node*2] < heap[node]){
							temp = heap[node*2];
							heap[node*2] = heap[node];
							heap[node] = temp;
							node = node*2;
						}else{
							break;
						}
					}else{
						if(heap[node*2+1] < heap[node]){
							temp = heap[node*2+1];
							heap[node*2+1] = heap[node];
							heap[node] = temp;
							node = node*2+1;
						}else{
							break;
						}
					}
				}
			}
		}else{
			heap[++idx] = op;
			int node = idx, temp = 0;	
			while(node != 1){
				if(heap[node] < heap[node/2]){
					temp = heap[node];
					heap[node] = heap[node/2];
					heap[node/2] = temp;
					node /= 2;
				}else{
					break;
				}
			}
		}
	}
	
	return 0;
}