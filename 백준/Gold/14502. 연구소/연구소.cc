#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;
using std::queue;

int BFS(int map[][8], int N, int M){
    int safeZone = 0;
    int capyMap[N][M]={};
    for(int i = 0; i < N; i++){ // 현재 맵 카피
        for(int j = 0; j < M; j++){
            capyMap[i][j] = map[i][j];
        }
    }
    
    int check[N][M]={};
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(capyMap[i][j] == 2){
                q.push(make_pair(i, j));
                check[i][j] = 1;
            }
        }
    }
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx < 0 || tx >= M || ty < 0 || ty >= N){
                continue;
            }
            if(check[ty][tx] == 0){
                check[ty][tx] = 1;
                if(capyMap[ty][tx] == 0){
                    capyMap[ty][tx] = 2;
                    q.push(make_pair(ty, tx));
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(capyMap[i][j] == 0){
                safeZone++;
            }
        }
    }
    
    return safeZone;
}

int virus(int map[][8], pair<int, int> start, int N, int M, int wall){
    if(wall >= 3){
        return BFS(map, N, M);
    }
    
    int max = 0, temp = 0;
    for(int i = start.first; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == start.first && j == 0){
                j = start.second;
            }
            if(map[i][j] == 0){
                map[i][j] = 1;
                temp = virus(map, make_pair(i, j), N, M, wall+1);
                if(temp > max){
                    max = temp;
                }
                map[i][j] = 0;
            }
        }
    }
    
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    int map[8][8]={};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    int max = virus(map, make_pair(0, 0), N, M, 0);
    
    cout << max << "\n";
    
    return 0;
}