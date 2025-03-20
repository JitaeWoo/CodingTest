#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, E = 0;
	cin >> N >> E;
	
	int map[N][N]={};
	int start = 0, end = 0, time = 0;
	for(int i = 0; i < E; i++){
		cin >> start >> end >> time;
		map[start-1][end-1] = time;
		map[end-1][start-1] = time;
	}
	
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	v1--; v2--;
	
	int node = 0, min = 1000, minNode = 0, temp = 0;
	int check[N]={}; // 방문 체크 용
	int distance[N][N]={}; // 최단거리 저장 배열
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i != j){
				distance[i][j] = 1000000;
			}
		}
	}
	
	int i = 0;
	while(i != N){
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
			
			check[minNode] = 1; // 최소값을 박제
			node = minNode;
		}
		
		for(int j = 0; j < N; j++){
			check[j] = 0;
		}
		
		if(i == v2){
			i = N;
		}
		if(i == v1){
			i = v2;
		}
		if(i == 0){
			i = v1;
		}
	}
	

	int distance1 = -1;
	int distance2 = -1;
	if(distance[0][v1] != 1000000 && distance[v1][v2] != 1000000 && distance[v2][N-1] != 1000000){
		distance1 = distance[0][v1]+distance[v1][v2]+distance[v2][N-1];
	}
	if(distance[0][v2] != 1000000 && distance[v2][v1] != 1000000 && distance[v1][N-1] != 1000000){
		distance2 = distance[0][v2]+distance[v2][v1]+distance[v1][N-1];
	}
	int result = distance1 < distance2 ? distance1 : distance2;
	
	cout << result << "\n";
	
	return 0;
}