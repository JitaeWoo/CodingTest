#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::copy;

string* MargeString(string* (&str), int len){
	if(len <= 1)
		return str;

	int Mlen1 = len/2;
	int Mlen2 = len - len/2;
	string * str1 = new string[Mlen1];
	string * str2 = new string[Mlen2];
	
	copy(&str[0], &str[Mlen1], &str1[0]);
	copy(&str[Mlen1], &str[len], &str2[0]);
	
	string* const (&Mstr1) = MargeString(str1, Mlen1);
	string* const (&Mstr2) = MargeString(str2, Mlen2);
	
	int i = 0, j = 0, resultIdx = 0;
	string * result = new string[len];
	while(true){
		if(i >= Mlen1 && j >= Mlen2){
			break;
		}else if(i >= Mlen1){
			result[resultIdx] = Mstr2[j];
			resultIdx++;
			j++;
		}else if(j >= Mlen2){
			result[resultIdx] = Mstr1[i];
			resultIdx++;
			i++;
		}else{
			if(Mstr1[i].length() < Mstr2[j].length()){
				result[resultIdx] = Mstr1[i];
				resultIdx++;
				i++;
			}else if(Mstr1[i].length() > Mstr2[j].length()){
				result[resultIdx] = Mstr2[j];
				resultIdx++;
				j++;
			}else{
				if(Mstr1[i] < Mstr2[j]){
					result[resultIdx] = Mstr1[i];
					resultIdx++;
					i++;
				}else{
					result[resultIdx] = Mstr2[j];
					resultIdx++;
					j++;
				}
			}
		}
	}
	
	return result;
}


int main(void){
	int N = 0;
	
	cin>>N;
	
	string* str = new string[N];
	
	for(int i = 0; i < N; i++){
		cin>>str[i];
	}
	
	string* const (&result) = MargeString(str, N);
	
	cout<<result[0]<<endl;
	for(int i = 1; i < N; i++){
		if(result[i].compare(result[i-1]) != 0)
			cout<<result[i]<<endl;
	}
	
	return 0;
}