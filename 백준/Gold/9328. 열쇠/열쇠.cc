#include <iostream>
#include <vector>
#include <list>
#include <string>

class thief{
    char map[100][100];
    bool check[100][100];
    std::list<std::pair<char, std::pair<int, int>>> doors;
    std::vector<char> keys;
    int height, width, doc;
    
public:
    thief(int h, int w){
        this->height = h;
        this->width = w;
        doc = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                std::cin >> map[i][j];
                if(map[i][j] == '*'){
                    check[i][j] = true;
                }
            }
        }
        
        std::string cur_keys = "";
        std::cin >> cur_keys;
        if(cur_keys[0] != '0'){
            for(int i = 0; i < cur_keys.length(); i++){
                keys.push_back(cur_keys[i]);
            }
        }
    }
    
    void move(int h, int w){
        check[h][w] = true;
        if(map[h][w] > 96){ // 열쇠이면
            keys.push_back(map[h][w]);
            map[h][w] = '.';
        }else if(map[h][w] > 64){ // 문이면
            doors.push_back(std::make_pair(map[h][w], std::make_pair(h, w)));
            map[h][w] = '.';
            return;
        }else{
            if(map[h][w] == '$'){
                doc++;
            }
        }
        
        int dh[4] = { 1, -1, 0, 0 };
        int dw[4] = { 0, 0, 1, -1 };
        for(int i = 0; i < 4; i++){
            int ch = h + dh[i];
            int cw = w + dw[i];
            
            if(ch < 0 || cw < 0 || ch >= height || cw >= width){
                continue;
            }
            
            if(check[ch][cw] == false){
                move(ch, cw);
            }
        }
    }
    
    int scan(){
        for(int i = 0; i < height; i++){ // 가장자리 탐색
            if(i == 0 || i == height-1){
                for(int j = 0; j < width; j++){
                    if(check[i][j] == false){
                        move(i, j);
                    }
                }
            }else{
                if(check[i][0] == false){
                    move(i, 0);
                }
                if(check[i][width-1] == false){
                    move(i, width-1);
                }
            }
        }
        
        std::list<std::pair<char, std::pair<int, int>>>::iterator iter;
        while(true){
            bool is_end = true;
            
            for(iter = doors.begin(); iter != doors.end(); iter++){
                for(char key : keys){
                    if(key - (*iter).first == 32){
                        move((*iter).second.first, (*iter).second.second);
                        doors.erase(iter);
                        is_end = false;
                        break;
                    }
                }
                if(!is_end){
                    break;
                }
            }
            
            if(is_end){
                break;
            }
        }
        
        return doc;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T = 0;
    std::cin >> T;
    
    for(int i = 0; i < T; i++){
        int h = 0, w = 0;
        std::cin >> h >> w;
        
        thief *th = new thief(h, w);
        
        int result = th->scan();
        
        std::cout << result << "\n";
    }
    
    
    return 0;
}