#include <iostream>
using std::cout;
using std::cin;
using std::ios;

void star(bool canvas[][8000], int N, int x, int y){
	if(N == 3){
		canvas[y][x] = true;
		canvas[y+1][x-1] = true; canvas[y+1][x+1] = true;
		for(int i = 0; i < 5; i++){
			canvas[y+2][x-2+i] = true;
		}
	}else{
		star(canvas, N/2, x, y);
		star(canvas, N/2, x-N/2, y+N/2);
		star(canvas, N/2, x+N/2, y+N/2);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	bool canvas[4000][8000]={};
	star(canvas, N, N-1, 0);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N*2-1; j++){
			if(canvas[i][j]){
				cout << '*';
			}else{
				cout << ' ';
			}
		}
		cout << "\n";
	}
	
	return 0;
}