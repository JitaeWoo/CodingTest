#include <iostream>
#include <algorithm>

void copy_board(int board[20][20], int (&c_board)[20][20]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            c_board[i][j] = board[i][j];
        }
    }
}

void move_left(int (&c_board)[20][20], int N, int level){
    // 왼쪽으로
    for(int i = 0; i < N; i++){ // 우선 왼쪽으로 모으기
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(c_board[i][j] != 0){
                c_board[i][idx] = c_board[i][j];
                if(idx != j){
                    c_board[i][j] = 0;
                }
                idx++;
            }
        }
    }
        
    
    for(int i = 0; i < N; i++){ // 같은 수 합치기
        for(int j = 0; j < N-1; j++){
            if(c_board[i][j] != 0 && c_board[i][j] == c_board[i][j+1]){
                c_board[i][j] *= 2;
                c_board[i][j+1] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 다시 왼쪽으로 모으기
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(c_board[i][j] != 0){
                c_board[i][idx] = c_board[i][j];
                if(idx != j){
                    c_board[i][j] = 0;
                }
                idx++;
            }
        }
    }
}

void move_right(int (&c_board)[20][20], int N){
    // 오른쪽으로
    for(int i = 0; i < N; i++){ // 우선 오른쪽으로 모으기
        int idx = N-1;
        for(int j = N-1; j >= 0; j--){
            if(c_board[i][j] != 0){
                c_board[i][idx] = c_board[i][j];
                if(idx != j){
                    c_board[i][j] = 0;
                }
                idx--;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 같은 수 합치기
        for(int j = N-1; j > 0; j--){
            if(c_board[i][j] != 0 && c_board[i][j] == c_board[i][j-1]){
                c_board[i][j] *= 2;
                c_board[i][j-1] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 다시 오른쪽으로 모으기
        int idx = N-1;
        for(int j = N-1; j >= 0; j--){
            if(c_board[i][j] != 0){
                c_board[i][idx] = c_board[i][j];
                if(idx != j){
                    c_board[i][j] = 0;
                }
                idx--;
            }
        }
    }
}

void move_up(int (&c_board)[20][20], int N){
    // 위쪽으로
    for(int i = 0; i < N; i++){ // 우선 위쪽으로 모으기
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(c_board[j][i] != 0){
                c_board[idx][i] = c_board[j][i];
                if(idx != j){
                    c_board[j][i] = 0;
                }
                idx++;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 같은 수 합치기
        for(int j = 0; j < N-1; j++){
            if(c_board[j][i] != 0 && c_board[j][i] == c_board[j+1][i]){
                c_board[j][i] *= 2;
                c_board[j+1][i] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 다시 위쪽으로 모으기
        int idx = 0;
        for(int j = 0; j < N; j++){
            if(c_board[j][i] != 0){
                c_board[idx][i] = c_board[j][i];
                if(idx != j){
                    c_board[j][i] = 0;
                }
                idx++;
            }
        }
    }
}

void move_down(int (&c_board)[20][20], int N, int level){
    // 아래쪽으로
    for(int i = 0; i < N; i++){ // 우선 아래쪽으로 모으기
        int idx = N-1;
        for(int j = N-1; j >= 0; j--){
            if(c_board[j][i] != 0){
                c_board[idx][i] = c_board[j][i];
                if(idx != j){
                    c_board[j][i] = 0;
                }
                idx--;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 같은 수 합치기
        for(int j = N-1; j > 0; j--){
            if(c_board[j][i] != 0 && c_board[j][i] == c_board[j-1][i]){
                c_board[j][i] *= 2;
                c_board[j-1][i] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++){ // 다시 아래쪽으로 모으기
        int idx = N-1;
        for(int j = N-1; j >= 0; j--){
            if(c_board[j][i] != 0){
                c_board[idx][i] = c_board[j][i];
                if(idx != j){
                    c_board[j][i] = 0;
                }
                idx--;
            }
        }
    }
}


int f2048(int board[20][20], int N, int level){
    if(level == 5){
        int max = 0;
        for(int i = 0; i < N; i++){
            int temp = *std::max_element(board[i], board[i]+N);
            if(max < temp){
                max = temp;
            }
        }
        return max;
    }else{
        int max = 0, temp = 0;
        int c_board[20][20]={};
        
        copy_board(board, c_board);
        move_left(c_board, N, level);
        temp = f2048(c_board, N, level + 1);
        if(temp > max){
            max = temp;
        }
        
        copy_board(board, c_board);
        move_right(c_board, N);
        temp = f2048(c_board, N, level + 1);
        if(temp > max){
            max = temp;
        }
        
        copy_board(board, c_board);
        move_up(c_board, N);
        temp = f2048(c_board, N, level + 1);
        if(temp > max){
            max = temp;
        }
        
        copy_board(board, c_board);
        move_down(c_board, N, level);
        temp = f2048(c_board, N, level + 1);
        if(temp > max){
            max = temp;
        }
        
        return max;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    int board[20][20]={};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> board[i][j];
        }
    }
    
    int result = f2048(board, N, 0);
    
    std::cout << result << "\n";
    
    
    return 0;
}