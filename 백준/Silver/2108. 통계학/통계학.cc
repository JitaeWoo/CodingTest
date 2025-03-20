#include <iostream>
#include <algorithm>
#include <cmath>
using std::cout;
using std::cin;
using std::ios;
using std::sort;
using std::round;

int main(void){
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int* NArray = new int[N];
	for(int i = 0; i < N; i++){
		cin >> NArray[i];
	}
	int sum = 0, max = -4000, min = 4000, median = 0, range = 0, average = 0;
	int freq[8001];
	for(int i = 0; i < 8001; i++){
		freq[i] = 0;
	}
	sort(NArray, NArray+N);
	
	for(int i = 0; i < N; i++){
		sum += NArray[i];
		if(max < NArray[i]){
			max = NArray[i];
		}
		if(min > NArray[i]){
			min = NArray[i];
		}
		
		freq[NArray[i] + 4000]++;
		if(i == N/2){
			median = NArray[i];
		}
	}
	delete[] NArray;
	average = round((float)sum / N);
	range = max - min;
	
	max = 0;
	for(int i = 0; i < 8001; i++){
		if(max < freq[i]){
			max = freq[i];
		}
	}
	
	int idx = 0;
	int* freqMax = new int[8001];
	for(int i = 0; i < 8001; i++){
		if(freq[i] == max){
			freqMax[idx++] = i - 4000;
		}
	}
	
	int resultFeq = 0;
	if(idx > 1){
		sort(freqMax, freqMax+idx);
		resultFeq = freqMax[1];
	}else{
		resultFeq = freqMax[0];
	}
	delete[] freqMax;
	
	cout << average << "\n";
	cout << median << "\n";
	cout << resultFeq << "\n";
	cout << range << "\n";
	
	return 0;
}