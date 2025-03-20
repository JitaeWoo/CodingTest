#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;
using std::queue;

class babyShark{
    int size = 2;
    int prey = 0;
    pair<int, int> pos;
    
	
public:
    babyShark(pair<int, int> pos){
        this->pos = pos;
    }
    
    int searchPrey(int map[][20], int N){ // 먹이 위치 탐색
        queue<pair<int, int>> q;
		q.push(pos);
		q.push(make_pair(-1, -1));
		int check[N][N]={};
		check[pos.first][pos.second] = 1;
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		int level = 0;
		bool isPrey = false;
		pair<int, int> result = make_pair(30, 30);
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(map[y][x] < size && map[y][x] != 0){ // 해당 장소에 먹을 수 있는 먹이가 있으면
				isPrey = true;
				if(result.first > y || (result.first == y && result.second > x)){
					result = make_pair(y, x);
				}
			}
			
			for(int i = 0; i < 4; i++){ // 상하좌우 탐색
				int tx = x + dx[i];
				int ty = y + dy[i];
				if(tx < 0 || tx >= N || ty < 0 || ty >= N){
					continue;
				}
				
				if(check[ty][tx] != 1 && map[ty][tx] <= size){
					check[ty][tx] = 1;
					q.push(make_pair(ty, tx));
				}
			}
			
			if(q.front().first == -1){
				if(isPrey){
					break;
				}else{
					q.pop();
					if(q.empty()){
						break;
					}
					level++;
					q.push(make_pair(-1, -1));
				}
			}
		}
		
		if(isPrey){
			preyOn(result, map);
			return level;
		}else{
			return 0;
		}
    }
    
    void preyOn(pair<int, int> result, int map[][20]){
		if(++prey == size && size < 8){
			prey = 0; 
			size++;
		}
		map[pos.first][pos.second] = 0;
		map[result.first][result.second] = 9;
		pos = result;
    }
};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    cin >> N;
    
    int map[20][20]={};
    babyShark* bs;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                bs = new babyShark(make_pair(i, j));
            }
        }
    }
    
	int result = 0, temp = -1;
	while(temp != 0){
		temp = bs->searchPrey(map, N);
		result += temp;
	}
	
	cout << result << "\n";
	
    return 0;
}