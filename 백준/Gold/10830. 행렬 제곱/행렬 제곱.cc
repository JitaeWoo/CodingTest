#include <iostream>
using std::cout;
using std::cin;
using std::ios;

void mul(int mat1[][5], int mat2[][5], int N){
	int result[N][N]={};
	for(int i = 0; i < N; i++){ // 계산
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				result[i][j] += mat1[i][k]*mat2[k][j];
			}
			result[i][j] %= 1000;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat1[i][j] = result[i][j];
		}
	}
}

void matrix(int mat[][5], long long B, int N){
	if(B == 1){
		return;
	}
	int temp[5][5]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			temp[i][j] = mat[i][j];
		}
	}
	matrix(temp, B/2, N);
	if(B % 2 == 0){
		mul(temp, temp, N);
	}else{
		mul(temp, temp, N);
		mul(temp, mat, N);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = temp[i][j];
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N = 0;
	long long B = 0L;
	cin >> N >> B;
	
	int mat[5][5]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mat[i][j];
			mat[i][j] %= 1000;
		}
	}
	
	matrix(mat, B, N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
    
    return 0;
}