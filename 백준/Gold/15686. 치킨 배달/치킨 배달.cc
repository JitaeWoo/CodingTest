#include <iostream>
#include <vector>
#include <cstdlib>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::pair;
using std::make_pair;
using std::abs;

int distCount(vector<pair<int, int>> chicken, vector<pair<int, int>> home){
    int dist = 0;
    for(pair<int, int> h : home){
        int min = 10000;
        for(pair<int, int> c : chicken){
            int temp = abs(c.first - h.first) + abs(c.second - h.second);
            if(min > temp){
                min = temp;
            }
        }
        dist += min;
    }
    
    return dist;
}

int chickenDist(vector<pair<int, int>> chicken, vector<pair<int, int>> home, int start, int M){
    static vector<pair<int, int>> TChicken;
    int min = 1000000, temp = 0;
    
    if(TChicken.size() >= M){
        return distCount(TChicken, home);
    }else{
        for(int i = start; i < chicken.size(); i++){
            TChicken.push_back(chicken[i]);
            temp = chickenDist(chicken, home, i+1, M);
            if(min > temp){
                min = temp;
            }
            TChicken.pop_back();
        }
    }
    
    return min;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, M = 0;
    cin >> N >> M;
    
    int map[N][N]={};
    vector<pair<int, int>> chicken;
    vector<pair<int, int>> home;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                chicken.push_back(make_pair(i, j));
            }else if(map[i][j] == 1){
                home.push_back(make_pair(i, j));
            }
        }
    }
    
    cout << chickenDist(chicken, home, 0, M) << "\n";
    
    return 0;
}