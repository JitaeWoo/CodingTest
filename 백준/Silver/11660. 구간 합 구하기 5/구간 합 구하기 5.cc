#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::pair;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int table[N+1][N+1]={};
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> table[i][j];
		}
	}
	
	int sumTable[N+1][N+1]={};
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int sum = table[i][j];
			sum += sumTable[i-1][j];
			sum += sumTable[i][j-1];
			sum -= sumTable[i-1][j-1];
			sumTable[i][j] = sum;
		}
	}
	
	for(int i = 0; i < M; i++){
		pair<int, int> start, end;
		cin >> start.first >> start.second >> end.first >> end.second;
		
		int result = sumTable[end.first][end.second] - sumTable[start.first-1][end.second] 
			- sumTable[end.first][start.second-1] + sumTable[start.first-1][start.second-1];
		
		cout << result << "\n";
	}
	
	return 0;
}