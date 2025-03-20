#include <iostream>
#include <string>

class sudoku{
    int board[9][9];
    
public:
    sudoku(){
        char char_board[9][9]={};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                std::cin >> char_board[i][j];
            }
        }
        
        // 편의상 int 형으로
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                board[i][j] = char_board[i][j] - 48;
            }
        }
    }
    
    // 스도쿠 풀이
    bool fill(int point){
        for(int i = point / 9; i < 9; i++){
            for(int j = point % 9; j < 9; j++){
                if(board[i][j] == 0){
                    for(int k = 1; k <= 9; k++){
                        if(check_num(k, i, j)){
                            board[i][j] = k;
                            if(fill(point+1)){
                                return true;
                            }
                            board[i][j] = 0;
                        }
                    }
                    return false;
                }
                point++;
            }
        }
        
        return true;
    }
    
    // 현재 칸에 이미 해당 숫자가 범위 내에 있는지
    bool check_num(int num, int a, int b){
        bool is_empty = true;
        
        for(int i = 0; i < 9; i++){
            if(board[a][i] == num || board[i][b] == num){
                is_empty = false;
            }
        }
        
        for(int i = a - a%3; i < a - a%3 + 3; i++){
            for(int j = b - b%3; j < b - b%3 + 3; j++){
                if(board[i][j] == num){
                    is_empty = false;
                }
            }
        }
        
        return is_empty;
    }
    
    void show_board(){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                std::cout << board[i][j];
            }
            std::cout << "\n";
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    sudoku sd = sudoku();
    
    sd.fill(0);
    
    sd.show_board();
    
    return 0;
}