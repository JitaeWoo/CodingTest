#include <iostream>

class Chess{
    int board[10][10];
    int size;
    
public:
    Chess(int size){
        this->size = size;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                std::cin >> board[i][j];
            }
        }
    } 
    
    int count(int start){
        int max = 0, temp = 0;
        int r = 0, c = 0;
        if(start < size){
            c = start;
        }else{
            c = size-1;
            r = start-(size-1);
        }
        
        int a = 0, b = 0;
        bool is_one = false;
        while(c >= 0 && r < size){
            if(board[r][c] == 1){
                is_one = true;
                temp = 1;
                int a = 1, b = 1;
                while(c+a < size && r+b < size){
                    if(board[r+b][c+a] == 1){
                        board[r+b][c+a] = 2;
                    }
                    a++;
                    b++;
                }
                    
                temp += count(start+1);
                                
                if(max < temp){
                    max = temp;
                }
                
                a = 1;
                b = 1;
                while(c+a < size && r+b < size){
                    if(board[r+b][c+a] == 2){
                        board[r+b][c+a] = 1;
                    }
                    a++;
                    b++;
                }
            }
            
            c--;
            r++;
        } 
        
        if(start < size*2-1 && !is_one){
            temp = count(start+1);
            if(max < temp){
                max = temp;
            }
        }
        
        return max;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int size = 0;
    std::cin >> size;
    
    Chess ch = Chess(size);
    
    int result = ch.count(0);
    
    std::cout << result << "\n";
    
    return 0;
}