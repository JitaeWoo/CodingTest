#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::ios;
using std::sort;

class Meeting{
public:
	int start = 0;
	int end = 0;
	
	Meeting(int start, int end){
		this->start = start;
		this->end = end;
	}
};

bool compare(Meeting* m1, Meeting* m2){
	int diff1 = m1->end - m1->start;
	int diff2 = m2->end - m1->start;
	
	if(diff1 == diff2){
		return m1->start < m2->start;
	}
	
	return diff1 < diff2;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	Meeting* m[N];
	int start = 0, end = 0;
	for(int i = 0; i < N; i++){
		cin >> start >> end;
		m[i] = new Meeting(start, end);
	}
	
	sort(m, m+N, compare);
	
	int min = 0, result = 0;
	for(int i = 0; i < N; i++){
		if(min <= m[i]->start){
			min = m[i]->end;
			result++;
		}
	}
	
	cout << result << "\n";
	
	return 0;
}