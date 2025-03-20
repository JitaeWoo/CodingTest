#include <iostream>
#include <cmath>
#include <vector>

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int N = 0;
	std::cin >> N;
	
	
	// 체 거르기
	bool sieve[N+1]={};
	for(int i = 2; i <= sqrt(N); i++){
		if(sieve[i] == 0){
			for(int j = i*2; j <= N; j += i){
				sieve[j] = 1;
			}
		}
	}
	
	std::vector<int> prime;
	std::vector<int>::iterator iter;
	for(int i = 2; i <= N; i++){
		if(sieve[i] == 0){
			prime.push_back(i);
		}
	}
	
	int result = 0;
	for(int i = 0; i < prime.size(); i++){
		int sum = 0;
		for(iter = prime.begin()+i; iter != prime.end() && sum < N; iter++){
			sum += *iter;
			if(sum == N){
				result++;
				break;
			}
		}
	}
	
	std::cout << result << "\n";
	
	
    return 0;
}