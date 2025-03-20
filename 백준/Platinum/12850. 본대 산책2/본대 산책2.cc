#include <iostream>
#define ll long long
#define INF 1000000007


void met_mul(ll (&result)[8][8], ll met1[8][8], ll met2[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            result[i][j] = 0;
            for(int k = 0; k < 8; k++){
                result[i][j] += met1[i][k] * met2[k][j];
                result[i][j] %= INF;
            }
            result[i][j] %= INF;
        }
    }
}

class walk{
    ll metrix[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
public:
    void square(ll (&met)[8][8], int D){
        if(D == 1){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    met[i][j] = metrix[i][j];
                }
            }
            return;
        }else if(D == 2){
            met_mul(met, metrix, metrix);
            return;
        }
        
        square(met, D/2);
        ll temp[8][8]={};
        met_mul(temp, met, met);
        if(D % 2 != 0){
            ll temp2[8][8]={};
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    temp2[i][j] = temp[i][j];
                }
            }
            
            met_mul(temp, temp2, metrix);
        }
        
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                met[i][j] = temp[i][j];
            }
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int D = 0;
    std::cin >> D;
    
    walk w;
    ll metrix[8][8]={};
    w.square(metrix, D);
    
    std::cout << metrix[0][0] << "\n";
    
    

    return 0;
}
