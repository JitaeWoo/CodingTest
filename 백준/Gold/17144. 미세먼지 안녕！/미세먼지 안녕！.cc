#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;

class airPurifier{
	int map[50][50];
	int R;
	int C;
	pair<int, int> point;
public:
	airPurifier(int R, int C){
		this->R = R;
		this->C = C;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> map[i][j];
			}
		}
		
		for(int i = 2; i < R; i++){
			if(map[i][0] == -1){
				point = make_pair(i, i+1);
				break;
			}
		}
	}
	
	void diffusion(){
		int tMap[50][50]={};
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(map[i][j] > 0){
					int count = 0;
					int dr[4] = {1, -1, 0, 0};
					int dc[4] = {0, 0, 1, -1};
					
					for(int k = 0; k < 4; k++){
						int tr = i + dr[k];
						int tc = j + dc[k];
						// 해당 방향이 벽이라면
						if(tr < 0 || tr >= R || tc < 0 || tc >= C){ 
							continue;
						}
						// 해당 방향이 공기청정기라면
						if((tr == point.first || tr == point.second) && tc == 0){
							continue;
						}
						
						tMap[tr][tc] += map[i][j]/5;
						count++;
					}
					
					tMap[i][j] += map[i][j] - (map[i][j]/5)*count;
				}
			}
		}
		
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(map[i][j] != -1){
					map[i][j] = tMap[i][j];
				}
			}
		}
	}
	
	void cleanAir(int T){
		for(int i = 0; i < T; i++){
			// 확산
			diffusion();
			
			// 윗부분 환기
			int r = point.first-2, c = 0;
			while(r >= 0){
				map[r+1][c] = map[r][c];
				r--;
			}
			r++; c++;
			while(c < C){
				map[r][c-1] = map[r][c];
				c++;
			}
			c--; r++;
			while(r <= point.first){
				map[r-1][c] = map[r][c];
				r++;
			}
			r--; c--;
			while(c > 0){
				map[r][c+1] = map[r][c];
				c--;
			}
			map[r][c+1] = 0;

			// 아랫부분 환기
			r = point.second+2; c = 0;
			while(r < R){
				map[r-1][c] = map[r][c];
				r++;
			}
			r--; c++;
			while(c < C){
				map[r][c-1] = map[r][c];
				c++;
			}
			c--; r--;
			while(r >= point.second){
				map[r+1][c] = map[r][c];
				r--;
			}
			r++; c--;
			while(c > 0){
				map[r][c+1] = map[r][c];
				c--;
			}
			map[r][c+1] = 0;
		}
	}
	
	void printDust(){
		int dust = 0;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(map[i][j] > 0){
					dust += map[i][j];
				}
			}
		}
		
		cout << dust << "\n";
	}
};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int R = 0, C = 0, T = 0;
	cin >> R >> C >> T;
	
	airPurifier* ap = new airPurifier(R, C);
	
	ap->cleanAir(T);
	
	ap->printDust();
	
    return 0;
}