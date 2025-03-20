#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::ios;
using std::queue;

class Teleport{
public:
	int x;
	int y;
	
	Teleport(int x, int y){
		this->x = x;
		this->y = y;
	}
};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	cin >> N >> M;
	
	Teleport* T[N+M];
	int x = 0, y = 0;
	for(int i = 0; i < N+M; i++){
		cin >> x >> y;
		T[i] = new Teleport(x, y);
	}
	
	int borad[101]={};
	borad[1] = 1;
	queue<int> q;
	int place = 1, level = 1, result = 0;
	bool isT = false;
	q.push(-1);
	while(true){
		for(int i = 1; i <= 6; i++){
			if(place+i == 100){
				result = level;
				break;
			}
			if(borad[place+i] != 1){
				borad[place+i] = 1;
				isT = false;
				for(int j = 0; j < N+M; j++){
					if(place+i == T[j]->x){
						if(borad[T[j]->y] != 1){
							borad[T[j]->y] = 1;
							q.push(T[j]->y);
						}
						isT = true;
						break;
					}
				}
				if(!isT){
					q.push(place+i);
				}
			}
		}
		if(result != 0){
			break;
		}
		if(q.front() == -1){
			q.pop();
			level++;
			q.push(-1);
		}
		place = q.front(); q.pop();
	}
	
	cout << result << "\n";
	
	return 0;
}