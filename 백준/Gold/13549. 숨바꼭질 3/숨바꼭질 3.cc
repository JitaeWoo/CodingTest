#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;
using std::pair;
using std::make_pair;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0, K = 0;
    cin >> N >> K;
    
    int map[200000]={};
    for(int i = 0; i < 200000; i++){
        map[i] = 100000;
    }
    map[N] = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    int result = 100000;
    while(!q.empty()){
        int node = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(node == K){
            if(result > time){
                result = time;
            }
        }else{
            if(node > 0 && map[node-1] > time+1){
                map[node-1] = time+1;
                q.push(make_pair(node-1, time+1));
            }
            if(node < 200000-1 && map[node+1] > time+1){
                map[node+1] = time+1;
                q.push(make_pair(node+1, time+1));
            }
            if(node*2 < 200000 && map[node*2] > time){
                map[node*2] = time;
                q.push(make_pair(node*2, time));
            }
        }
    }
    
    cout << result << "\n";
    
   return 0;
}