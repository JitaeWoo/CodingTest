#include <iostream>
#define pii std::pair<int,int>

void copy_board(char board[10][10], char (&c_board)[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            c_board[i][j] = board[i][j];
        }
    }
}

// 이동 함수 (2 : blue 탈출, 1 : red만 탈출, 0 : 탈출 x)
int move_left(char (&board)[10][10], int N, int M, pii &red, pii &blue){
    bool red_exit = false;
    
    // red 왼쪽 이동
    for(int i = red.second-1; i >= 0; i--){
        if(board[red.first][i] != '.'){
            board[red.first][red.second] = '.';
            if(board[red.first][i] == 'O'){
                red_exit = true;
            }else{
                board[red.first][i+1] = 'R';
                red.second = i+1;
            }
            break;
        }
    }
    
    // blue 왼쪽 이동
    for(int i = blue.second-1; i >= 0; i--){
        if(board[blue.first][i] != '.'){
            board[blue.first][blue.second] = '.';
            if(board[blue.first][i] == 'O'){
                return 2;
            }else{
                board[blue.first][i+1] = 'B';
                blue.second = i+1;
            }
            break;
        }
    }
    
    // 다시 red 왼쪽 이동
    if(red_exit){
        return 1;
    }else{
        for(int i = red.second-1; i >= 0; i--){
            if(board[red.first][i] != '.'){
                board[red.first][red.second] = '.';
                if(board[red.first][i] == 'O'){
                    red_exit = true;
                }else{
                    board[red.first][i+1] = 'R';
                    red.second = i+1;
                }
                break;
            }
        }
    }
    
    if(red_exit){
        return 1;
    }else{
        return 0;
    }
}

int move_right(char (&board)[10][10], int N, int M, pii &red, pii &blue){
    bool red_exit = false;
    
    // red 오른쪽 이동
    for(int i = red.second+1; i < M; i++){
        if(board[red.first][i] != '.'){
            board[red.first][red.second] = '.';
            if(board[red.first][i] == 'O'){
                red_exit = true;
            }else{
                board[red.first][i-1] = 'R';
                red.second = i-1;
            }
            break;
        }
    }
    
    // blue 오른쪽 이동
    for(int i = blue.second+1; i < M; i++){
        if(board[blue.first][i] != '.'){
            board[blue.first][blue.second] = '.';
            if(board[blue.first][i] == 'O'){
                return 2;
            }else{
                board[blue.first][i-1] = 'B';
                blue.second = i-1;
            }
            break;
        }
    }
    
    // 다시 red 오른쪽 이동
    if(red_exit){
        return 1;
    }else{
        for(int i = red.second+1; i < M; i++){
            if(board[red.first][i] != '.'){
                board[red.first][red.second] = '.';
                if(board[red.first][i] == 'O'){
                    red_exit = true;
                }else{
                    board[red.first][i-1] = 'R';
                    red.second = i-1;
                }
                break;
            }
        }
    }
    
    if(red_exit){
        return 1;
    }else{
        return 0;
    }
}

int move_up(char (&board)[10][10], int N, int M, pii &red, pii &blue){
    bool red_exit = false;
    
    // red 위쪽 이동
    for(int i = red.first-1; i >= 0; i--){
        if(board[i][red.second] != '.'){
            board[red.first][red.second] = '.';
            if(board[i][red.second] == 'O'){
                red_exit = true;
            }else{
                board[i+1][red.second] = 'R';
                red.first = i+1;
            }
            break;
        }
    }
    
    // blue 위쪽 이동
    for(int i = blue.first-1; i >= 0; i--){
        if(board[i][blue.second] != '.'){
            board[blue.first][blue.second] = '.';
            if(board[i][blue.second] == 'O'){
                return 2;
            }else{
                board[i+1][blue.second] = 'B';
                blue.first = i+1;
            }
            break;
        }
    }
    
    // 다시 red 위쪽 이동
    if(red_exit){
        return 1;
    }else{
        for(int i = red.first-1; i >= 0; i--){
            if(board[i][red.second] != '.'){
                board[red.first][red.second] = '.';
                if(board[i][red.second] == 'O'){
                    red_exit = true;
                }else{
                    board[i+1][red.second] = 'R';
                    red.first = i+1;
                }
                break;
            }
        }
    }
    
    if(red_exit){
        return 1;
    }else{
        return 0;
    }
}

int move_down(char (&board)[10][10], int N, int M, pii &red, pii &blue){
    bool red_exit = false;
    
    // red 아래쪽 이동
    for(int i = red.first+1; i < N; i++){
        if(board[i][red.second] != '.'){
            board[red.first][red.second] = '.';
            if(board[i][red.second] == 'O'){
                red_exit = true;
            }else{
                board[i-1][red.second] = 'R';
                red.first = i-1;
            }
            break;
        }
    }
    
    // blue 아래쪽 이동
    for(int i = blue.first+1; i < N; i++){
        if(board[i][blue.second] != '.'){
            board[blue.first][blue.second] = '.';
            if(board[i][blue.second] == 'O'){
                return 2;
            }else{
                board[i-1][blue.second] = 'B';
                blue.first = i-1;
            }
            break;
        }
    }
    
    // 다시 red 아래쪽 이동
    if(red_exit){
        return 1;
    }else{
        for(int i = red.first+1; i < N; i++){
            if(board[i][red.second] != '.'){
                board[red.first][red.second] = '.';
                if(board[i][red.second] == 'O'){
                    red_exit = true;
                }else{
                    board[i-1][red.second] = 'R';
                    red.first = i-1;
                }
                break;
            }
        }
    }
    
    if(red_exit){
        return 1;
    }else{
        return 0;
    }
}

int bead(char board[10][10], int N, int M, pii red, pii blue, int level){
    if(level >= 10){
        return -1;
    }else{
        int result = -1;
        int op = 0;
        pii c_red, c_blue;
        char c_board[10][10]={};
        
        int (*fptr[4])(char (&)[10][10], int, int, pii&, pii&) 
            = {move_left, move_right, move_up, move_down};
        
        for(int i = 0; i < 4; i++){
            copy_board(board, c_board);
            c_red = red; c_blue = blue;
            
            op = fptr[i](c_board, N, M, c_red, c_blue);
            if(op == 0){
                int temp = bead(c_board, N, M, c_red, c_blue, level+1);
                if(temp != -1){
                    if(result == -1){
                        result = temp;
                    }else{
                        if(result > temp){
                            result = temp;
                        }
                    }
                }
            }else if(op == 1){
                return level + 1;
            }
        }
        
        return result;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0, M = 0;
    std::cin >> N >> M;
    
    char board[10][10]={};
    pii red, blue;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> board[i][j];
            if(board[i][j] == 'R'){
                red = std::make_pair(i, j);
            }else if(board[i][j] == 'B'){
                blue = std::make_pair(i, j);
            }
        }
    }
    
    int result = bead(board, N, M, red, blue, 0);
    
    std::cout << result << "\n";
    

    return 0;
}
