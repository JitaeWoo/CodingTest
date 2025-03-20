#include <iostream>
using std::cout;
using std::cin;
using std::ios;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0, M = 0, B = 0;
	cin >> N >> M >> B;
	
	int NArray[N][M];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> NArray[i][j];
		}
	}
	
	int time = 0, block = 0, resultTime = 200000000, resultHeight = 0;
	for(int i = 0; i <= 256; i++){
		block = B;
		time = 0;
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(NArray[j][k] > i){
					time += (NArray[j][k] - i)*2;
					block += NArray[j][k] - i;
				}else if(NArray[j][k] < i){
					time += i - NArray[j][k];
					block -= i - NArray[j][k];
				}
			}
		}
		
		
		if(time <= resultTime && block >= 0){
			resultTime = time;
			resultHeight = i;
		}
	}
	
	cout << resultTime << " " << resultHeight << "\n";
	
	return 0;
}