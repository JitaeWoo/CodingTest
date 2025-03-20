#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int abs(int num){
	if(num < 0){
		return num*(-1);
	}else{
		return num;
	}
}

int main(void){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int num = 0;
	int heap[100001]={};
	for(int i = 0; i < 100001; i++){
		heap[i] = 2147483647;
	}
	int idx = 0, temp = 0;
	for(int i = 0; i < N; i++){
		cin >> num;
		
		if(num == 0){
			if(idx == 0){
				cout << "0\n";
				continue;
			}
			cout << heap[1] << "\n";
			heap[1] = heap[idx];
			heap[idx--] = 2147483647;
			temp = 1;
			while(temp*2 <= 100000){
				if(abs(heap[temp*2]) < abs(heap[temp*2+1])){
					if(abs(heap[temp]) > abs(heap[temp*2])){
						num = heap[temp];
						heap[temp] = heap[temp*2];
						heap[temp*2] = num;
						temp = temp*2;
					}else if(abs(heap[temp]) == abs(heap[temp*2])){
						if(heap[temp] > heap[temp*2]){
							num = heap[temp];
							heap[temp] = heap[temp*2];
							heap[temp*2] = num;
							temp = temp*2;
						}else{
							break;
						}
					}else{
						break;
					}
				}else if(abs(heap[temp*2]) == abs(heap[temp*2+1])){
					if(heap[temp*2] < heap[temp*2+1]){
						if(abs(heap[temp]) > abs(heap[temp*2])){
							num = heap[temp];
							heap[temp] = heap[temp*2];
							heap[temp*2] = num;
							temp *= 2;
						}else if(abs(heap[temp]) == abs(heap[temp*2])){
							if(heap[temp] > heap[temp*2]){
								num = heap[temp];
								heap[temp] = heap[temp*2];
								heap[temp*2] = num;
								temp = temp*2;
							}else{
								break;
							}
						}else{
							break;
						}
					}else{
						if(abs(heap[temp]) > abs(heap[temp*2+1])){
							num = heap[temp];
							heap[temp] = heap[temp*2+1];
							heap[temp*2+1] = num;
							temp = temp*2+1;
						}else if(abs(heap[temp]) == abs(heap[temp*2+1])){
							if(heap[temp] > heap[temp*2+1]){
								num = heap[temp];
								heap[temp] = heap[temp*2+1];
								heap[temp*2+1] = num;
								temp = temp*2+1;
							}else{
								break;
							}
						}else{
							break;
						}
					}
				}else{
					if(abs(heap[temp]) > abs(heap[temp*2+1])){
						num = heap[temp];
						heap[temp] = heap[temp*2+1];
						heap[temp*2+1] = num;
						temp = temp*2+1;
					}else if(abs(heap[temp]) == abs(heap[temp*2+1])){
						if(heap[temp] > heap[temp*2+1]){
							num = heap[temp];
							heap[temp] = heap[temp*2+1];
							heap[temp*2+1] = num;
							temp = temp*2+1;
						}else{
							break;
						}
					}else{
						break;
					}
				}
			}
		}else{
			heap[++idx] = num;
			temp = idx;
			while(temp != 1){
				if(abs(heap[temp]) < abs(heap[temp/2])){
					num = heap[temp];
					heap[temp] = heap[temp/2];
					heap[temp/2] = num;
					temp /= 2;
				}else if(abs(heap[temp]) == abs(heap[temp/2])){
					if(heap[temp] < heap[temp/2]){
						num = heap[temp];
						heap[temp] = heap[temp/2];
						heap[temp/2] = num;
						temp /= 2;
					}else{
						break;
					}
				}else{
					break;
				}
			}
		}
	}
	
	return 0;
}