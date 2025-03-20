#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::ios;
using std::vector;
using std::pair;
using std::make_pair;

long long Fibonacci(long long N){
	static vector<pair<long long, long long>> DP;
	
	for(pair<long long, long long> item : DP){
		if(item.first == N){
			return item.second;
		}
	}
	
	if(N == 0){
		return 0L;
	}else if(N == 1){
		return 1L;
	}else if(N == 2){
		return 1L;
	}else{
		long long result = (Fibonacci(N/2+1)*Fibonacci(N-N/2) + Fibonacci(N/2)*Fibonacci(N-1-N/2)) % 1000000007;
		DP.push_back(make_pair(N, result));
		return result;
	}
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n = 0;
	cin >> n;
	
	long long result = Fibonacci(n);
	
	cout << result << "\n";
	
	
	return 0;
}