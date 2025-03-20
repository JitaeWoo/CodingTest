#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::pair;
using std::make_pair;
using std::queue;

class pipe{
public:
	pair<int, int> point;
	int angle; // 현재 상태, 가로=1, 세로=2, 대각선=3
	
	pipe(pair<int, int> point, int angle){
		this->point = point;
		this->angle = angle;
	}
	
	void move1(queue<pipe*>* q, int map[][16], int N){
		if(point.second+1 < N && map[point.first][point.second+1] != 1){
			q->push(new pipe(make_pair(point.first, point.second+1), 1));
			if(point.first+1 < N && map[point.first+1][point.second] != 1 && map[point.first+1][point.second+1] != 1){
				q->push(new pipe(make_pair(point.first+1, point.second+1), 3));
			}
		}
	}
	
	void move2(queue<pipe*>* q, int map[][16], int N){
		if(point.first+1 < N && map[point.first+1][point.second] != 1){
			q->push(new pipe(make_pair(point.first+1, point.second), 2));
			if(point.second+1 < N && map[point.first][point.second+1] != 1 && map[point.first+1][point.second+1] != 1){
				q->push(new pipe(make_pair(point.first+1, point.second+1), 3));
			}
		}
	}
	
	void move3(queue<pipe*>* q, int map[][16], int N){
		bool b1 = false, b2 = false;

		if(point.second+1 < N && map[point.first][point.second+1] != 1){
			q->push(new pipe(make_pair(point.first, point.second+1), 1));
			b1 = true;
		}
		
		if(point.first+1 < N && map[point.first+1][point.second] != 1){
			q->push(new pipe(make_pair(point.first+1, point.second), 2));
			b2 = true;
		}
		
		if(b1 && b2 && map[point.first+1][point.second+1] != 1){
			q->push(new pipe(make_pair(point.first+1, point.second+1), 3));
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int map[16][16]={};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	pipe* p = new pipe(make_pair(0, 1), 1);
	queue<pipe*> q;
	q.push(p);
	int result = 0;
	while(!q.empty()){
		pipe* tp = q.front();
		q.pop();
		
		if(tp->point == make_pair(N-1, N-1)){
			result++;
			continue;
		}
		
		if(tp->angle == 1){
			tp->move1(&q, map, N);
		}else if(tp->angle == 2){
			tp->move2(&q, map, N);
		}else{
			tp->move3(&q, map, N);
		}
	}
	
	cout << result << "\n";
	
    return 0;
}