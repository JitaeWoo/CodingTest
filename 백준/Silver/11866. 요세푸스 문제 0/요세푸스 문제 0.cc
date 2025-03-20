#include <iostream>
#include <list>
using std::cout;
using std::cin;
using std::ios;
using std::list;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0, K = 0;
	cin >> N >> K;
	int * NArray = new int[N];
	list<int> NList;
	
	for(int i = 0; i < N; i++){
		NList.push_back(i+1);
	}
	
	int j = 0, idx = 0;
	list<int>::iterator iter;
	iter = NList.begin();
	iter--;
	while(NList.size() != 0){
		j = 0;
		if(iter == NList.end()){
			iter = NList.begin();
		}
		while(j < K - 1){
			iter++;
			if(iter == NList.end()){
				iter = NList.begin();
			}
			j++;
		}
		NArray[idx++] = *iter;
		iter = NList.erase(iter);
	}
	
	cout << "<";
	
	for(int i = 0; i < N; i++){
		if(i != N-1){
			cout << NArray[i] << ", ";
		}else{
			cout << NArray[i];
		}
	}
	cout << ">\n";
	
	return 0;
}