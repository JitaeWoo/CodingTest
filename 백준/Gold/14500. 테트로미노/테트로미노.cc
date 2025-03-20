#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int f1(int paper[][500], char direction, int n, int m, int num){
	if(num == 4){
		return paper[n][m];
	}
	
	int max = 0, temp = 0;
	if(direction != 'L' && m > 0 && paper[n][m-1] != 0){
		temp = f1(paper, 'R', n, m-1, num+1);
		if(max < temp){
			max = temp;
		}
	}
	if(direction != 'R' && m < 499 && paper[n][m+1] != 0){
		temp = f1(paper, 'L', n, m+1, num+1);
		if(max < temp){
			max = temp;
		}
	}
	if(direction != 'D' && n > 0 && paper[n-1][m] != 0){
		temp = f1(paper, 'U', n-1, m, num+1);
		if(max < temp){
			max = temp;
		}
	}
	if(direction != 'U' && n < 499 && paper[n+1][m] != 0){
		temp = f1(paper, 'D', n+1, m, num+1);
		if(max < temp){
			max = temp;
		}
	}
	
	return max + paper[n][m];
}

int T(int paper[][500], int n, int m){
	int num[4]={};
	int min = 1000;
	if(m > 0){
		num[0] = paper[n][m-1];
		if(min > num[0]){
			min = num[0];
		}
	}else{
		min = 0;
	}
	
	if(m < 499){
		num[1] = paper[n][m+1];
		if(min > num[1]){
			min = num[1];
		}
	}else{
		min = 0;
	}
	
	if(n > 0){
		num[2] = paper[n-1][m];
		if(min > num[2]){
			min = num[2];
		}
	}else{
		min = 0;
	}
	
	if(n < 499){
		num[3] = paper[n+1][m];
		if(min > num[3]){
			min = num[3];
		}
	}else{
		min = 0;
	}
	
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum += num[i];
	}
	
	return paper[n][m] + sum - min;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	int paper[500][500]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> paper[i][j];
		}
	}
	
	int max = 0, temp = 0, tempT = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			temp = f1(paper, 'S', i, j, 1);
			tempT = T(paper, i, j);
			if(tempT > temp){
				temp = tempT;
			}
			if(max < temp){
				max = temp;
			}
		}
	}
	
	cout << max << "\n";
	
	return 0;
}