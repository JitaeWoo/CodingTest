#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0, X = 0;
	cin >> N >> M >> X;
	
	int map[N][N]={};
	int start = 0, end = 0, time = 0;
	for(int i = 0; i < M; i++){
		cin >> start >> end >> time;
		map[start-1][end-1] = time;
	}
	
	int node = 0, min = 1000, minNode = 0, temp = 0;
	int check[N]={}; // 방문 체크 용
	int distance[N][N]={}; // 최단거리 저장 배열
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i != j){
				distance[i][j] = 100000;
			}
		}
	}
	for(int i = 0; i < N; i++){
		node = i;
		check[node] = 1;
		for(int k = 0; k < N-1; k++){
			min = 1000000;
			for(int j = 0; j < N; j++){
				if(map[node][j] != 0 && check[j] != 1){
					temp = distance[i][node] + map[node][j];
					if(distance[i][j] > temp){
						distance[i][j] = temp;
					}
				}
			}
			
			for(int j = 0; j < N; j++){ // 이번 단계에서의 최소값 탐색
				if(check[j] != 1){
					if(distance[i][j] < min){
						min = distance[i][j];
						minNode = j;
					}
				}
			}
			if(minNode == X-1){ // X를 찾았으면 나가기
				break;
			}
			check[minNode] = 1; // 최소값을 박제
			node = minNode;
		}
		
		for(int j = 0; j < N; j++){
			check[j] = 0;
		}
	}
	
	int result = 0;
	for(int i = 0; i < N; i++){
		if(distance[i][X-1] + distance[X-1][i] > result){
			result = distance[i][X-1] + distance[X-1][i];
		}
	}
	
	cout << result << "\n";
	
	return 0;
}