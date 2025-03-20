#include <iostream>
#include <list>
using std::cout;
using std::cin;
using std::ios;
using std::list;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int M = 0, document = 0;
		cin >> M >> document;
		
		list<int> MList;
		int prior = 0;
		for(int j = 0; j < M; j++){
			cin >> prior;
			MList.push_back(prior);
		}
		int result = 1;
		list<int>::iterator iter;
		while(MList.size() != 0){
			bool isPop = true;
			iter = MList.begin();
			iter++;		
			for(; iter != MList.end(); iter++){
				if(MList.front() < *iter){
					int temp = MList.front();
					MList.pop_front();
					MList.push_back(temp);
					isPop = false;
					if(document > 0){
						document--;
					}else{
						document = MList.size() - 1;
					}
					break;
				}
			}
			if(isPop){
				if(document == 0){
					cout << result << "\n";
					break;
				}
				MList.pop_front();
				document--;
				result++;
			}
		}
	}
	
	return 0;
}