#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int n = 0;
	int truePeople[50]={};
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> truePeople[i]; 
	}
	
	int party[50][51]={};
	int m = 0;
	for(int i = 0; i < M; i++){ // 파티 참여 인원 입력
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> party[i][j];
		}
	}
	if(n == 0){ // 진실을 아는 사람이 없으면 파티 수 출력
		cout << M << "\n";
		return 0;
	}
	
	int check[50]={};
	int checkPeople[N]={};
	queue<int> q;
	for(int i = 0; i < n; i++){
		q.push(truePeople[i]);
		checkPeople[truePeople[i]] = 1;
	}
	int trueMan = q.front(); q.pop();
	bool isTrueMan = false;
	while(true){
		for(int i = 0; i < M; i++){
			isTrueMan = false;
			if(check[i] != 1){
				for(int j = 0; party[i][j] != 0; j++){
					if(party[i][j] == trueMan){
						check[i] = 1;
						isTrueMan = true;
					}
				}
			}
			
			if(isTrueMan){
				for(int j = 0; party[i][j] != 0; j++){
					if(checkPeople[party[i][j]] != 1){
						q.push(party[i][j]);
						checkPeople[party[i][j]] = 1;
					}
				}
			}
		}
		
		if(q.empty()){
			break;
		}else{
			trueMan = q.front(); q.pop();
		}
	}
	
	int result = 0;
	for(int i = 0; i < M; i++){
		if(check[i] == 0){
			result++;
		}
	}
	
	cout << result << "\n";
	
	
	return 0;
}