#include <iostream>

class stairs_num{
	long long DP[101][10][1024]={};
	int N;
	
public:
	stairs_num(int N){
		this->N = N;
		
		for(int i = 0; i < 101; i++){
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < 1024; k++){
					DP[i][j][k] = -1;
				}
			}
		}
	}
	
	long long stairs_count(int num, int level, int bit){
		if(DP[level][num][bit] != -1){
			return DP[level][num][bit];
		}
		
		bit |= 1 << num;
		
		
		if(level == N){
			if(bit == 1023){
				return DP[level][num][bit] = 1;
			}
		}else{
			long long temp = 0;
			if(num < 9){
				temp += stairs_count(num+1, level+1, bit);
			}
			if(num > 0){
				temp += stairs_count(num-1, level+1, bit);
			}
			
			return DP[level][num][bit] = temp % 1000000000;
		}
		
		return 0;
	}
};

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int N = 0;
	std::cin >> N;
	
	stairs_num sn(N);
	
	int result = 0;
	for(int i = 1; i <= 9; i++){
		result += sn.stairs_count(i, 1, 0);
		result %= 1000000000;
	}
	
	std::cout << result << "\n";
	
    return 0;
}