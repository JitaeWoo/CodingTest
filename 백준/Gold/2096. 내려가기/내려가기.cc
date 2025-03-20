#include <iostream>
using std::cout;
using std::cin;
using std::ios;
#define MAX2(x, y) (x > y ? x : y)
#define MIN2(x, y) (x < y ? x : y)
#define MAX3(x, y, z) (x > y ? (x > z ? x : z) : (y > z ? y : z))
#define MIN3(x, y, z) (x < y ? (x < z ? x : z) : (y < z ? y : z))


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int a = 0, b = 0, c = 0;
	int map[3]={}, maxDP[2][3]={}, minDP[2][3]={};
	for(int i = 0; i < N; i++){
		cin >> a >> b >> c;
		map[0] = a;
		map[1] = b;
		map[2] = c;
		
		maxDP[1][0] = map[0] + MAX2(maxDP[0][0], maxDP[0][1]);
		maxDP[1][1] = map[1] + MAX3(maxDP[0][0], maxDP[0][1], maxDP[0][2]);
		maxDP[1][2] = map[2] + MAX2(maxDP[0][1], maxDP[0][2]);
		minDP[1][0] = map[0] + MIN2(minDP[0][0], minDP[0][1]);
		minDP[1][1] = map[1] + MIN3(minDP[0][0], minDP[0][1], minDP[0][2]);
		minDP[1][2] = map[2] + MIN2(minDP[0][1], minDP[0][2]);
		
		maxDP[0][0] = maxDP[1][0];
		maxDP[0][1] = maxDP[1][1];
		maxDP[0][2] = maxDP[1][2];
		minDP[0][0] = minDP[1][0];
		minDP[0][1] = minDP[1][1];
		minDP[0][2] = minDP[1][2];
	}
	
	cout << MAX3(maxDP[1][0], maxDP[1][1], maxDP[1][2]) << " " 
		<< MIN3(minDP[1][0], minDP[1][1], minDP[1][2]) << "\n";
	
	return 0;
}