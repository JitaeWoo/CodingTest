#include <iostream>
#define INF 9999

class bulb_game{
    char board[10][10];
    char c_board[10][10];
public:
    bulb_game(){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                std::cin >> board[i][j];
            }
        }
    }
    
    void change(int i, int j){
        if(c_board[i][j] == 'O'){
            c_board[i][j] = '#';
        }else{
            c_board[i][j] = 'O';
        }
    }
    
    void click(int i, int j){
        change(i, j);
        
        if(i > 0){
            change(i-1, j);
        }
        if(j > 0){
            change(i, j-1);
        }
        if(i < 9){
            change(i+1, j);
        }
        if(j < 9){
            change(i, j+1);
        }
    }
    
    void copy_board(){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                c_board[i][j] = board[i][j];
            }
        }
    }
    
    int count(){
        int min = INF;
        for(int i = 0; i < (1 << 10); i++){
            int clicks = 0;
            copy_board();
            
            for(int j = 0; j < 10; j++){
                if(i & (1 << j)){
                    click(0, j);
                    clicks++;
                }
            }
            
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10; k++){
                    if(c_board[j][k] == 'O'){
                        click(j+1, k);
                        clicks++;
                    }
                }
            }
            
            bool is_clear = true;
            for(int j = 0; j < 10; j++){
                if(c_board[9][j] == 'O'){
                    is_clear = false;
                    break;
                }
            }
            
            if(is_clear){
                if(clicks < min){
                    min = clicks;
                }
            }
        }
            
        return min;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    bulb_game bg;
    int result = bg.count();
    std::cout << result << "\n";

    return 0;
}
