#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::sort;

class Point{
	public:
	int x;
	int y;
	
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

bool Compare(Point* first, Point* second){
	if(first->x != second->x){
		return first->x < second->x;
	}else{
		return first->y < second->y;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0;
	cin >> N;
	
	Point * pointArray[N];
	int x = 0;
	int y = 0;
	for(int i = 0; i < N; i++){
		cin >> x;
		cin >> y;
		pointArray[i] = new Point(x, y);
	}
	
	sort(pointArray, pointArray+N, Compare);
	
	for(int i = 0; i < N; i++){
		cout << pointArray[i]->x << " " << pointArray[i]->y << "\n";
	}
}