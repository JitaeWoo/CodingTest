#include <iostream>
#include <string>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::string;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	string str = "";
	char map[N][M]={};
	int n = 0, m = 0;
	for(int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < M; j++){
			map[i][j] = str[j];
			if(str[j] == 'I'){
				n = i;
				m = j;
			}
		}
	}
	
	int check[N][M]={};
	queue<int> q;
	int people = 0;
	while(true){
		if(n > 0 && check[n-1][m] == 0){
			check[n-1][m] = 1;
			if(map[n-1][m] != 'X'){
				q.push(n-1);
				q.push(m);
				if(map[n-1][m] == 'P'){
					people++;
				}
			}
		}
		if(n < N-1 && check[n+1][m] == 0){
			check[n+1][m] = 1;
			if(map[n+1][m] != 'X'){
				q.push(n+1);
				q.push(m);
				if(map[n+1][m] == 'P'){
					people++;
				}
			}
		}
		if(m > 0 && check[n][m-1] == 0){
			check[n][m-1] = 1;
			if(map[n][m-1] != 'X'){
				q.push(n);
				q.push(m-1);
				if(map[n][m-1] == 'P'){
					people++;
				}
			}
		}
		if(m < M-1 && check[n][m+1] == 0){
			check[n][m+1] = 1;
			if(map[n][m+1] != 'X'){
				q.push(n);
				q.push(m+1);
				if(map[n][m+1] == 'P'){
					people++;
				}
			}
		}
		
		if(q.empty()){
			break;
		}else{
			n = q.front(); q.pop();
			m = q.front(); q.pop();
		}
	}
	
	if(people == 0){
		cout << "TT\n";
	}else{
		cout << people << "\n";
	}
	
	
	return 0;
}