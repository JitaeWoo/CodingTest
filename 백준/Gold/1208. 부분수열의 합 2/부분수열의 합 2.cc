#include <iostream>
#include <map>

void left(std::map<int, int> &sums, int nums[], int N, int start){
	static int sum = 0;
	
	sums[sum]++;
	
	for(int i = start; i < N; i++){
		sum += nums[i];
		left(sums, nums, N, i+1);
		sum -= nums[i];
	}
}

long long right(std::map<int, int> &sums, int nums[], int N, int S, int start){
	static int sum = 0;
	static long long result = 0;
	
	result += sums[S-sum];
	
	for(int i = start; i < N; i++){
		sum += nums[i];
		right(sums, nums, N, S, i+1);
		sum -= nums[i];
	}
	
	return result;
}


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	int N = 0, S = 0;
	std::cin >> N >> S;
	
	int nums[N]={};
	for(int i = 0; i < N; i++){
		std::cin >> nums[i];
	}
	
	std::map<int, int> sums;
	left(sums, nums, N/2, 0);
	long long result = right(sums, nums, N, S, N/2);
	if(S == 0){
		result--;
	}
	
	std::cout << result << "\n";
	
    return 0;
}