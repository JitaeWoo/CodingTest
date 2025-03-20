#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int f1(char board[][21], int r, int c){
	static int alpha[26];
	alpha[board[r][c]-65] = 1;
	int temp = 0, max = 0;
	if(c > 0){
		if(alpha[board[r][c-1]-65] != 1){
			temp = 1 + f1(board, r, c-1);
			if(temp > max){
				max = temp;
			}
		}
	}
	
	if(c < 20 && board[r][c+1] != 0){
		if(alpha[board[r][c+1]-65] != 1){
			temp = 1 + f1(board, r, c+1);
			if(temp > max){
				max = temp;
			}
		}
	}
	
	if(r > 0){
		if(alpha[board[r-1][c]-65] != 1){
			temp = 1 + f1(board, r-1, c);
			if(temp > max){
				max = temp;
			}
		}
	}
	
	if(r < 20 && board[r+1][c] != 0){
		if(alpha[board[r+1][c]-65] != 1){
			temp = 1 + f1(board, r+1, c);
			if(temp > max){
				max = temp;
			}
		}
	}
	
	alpha[board[r][c]-65] = 0;
	
	return max;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int R = 0, C = 0;
	cin >> R >> C;
	
	char board[21][21]={};
	string str = "";
	for(int i = 0; i < R; i++){
		cin >> str;
		for(int j = 0; j < C; j++){
			board[i][j] = str[j];
		}
	}
	str = "";
	str += board[0][0];
	
	int max = f1(board, 0, 0);
	
	cout << max+1 << "\n";
	
	return 0;
}