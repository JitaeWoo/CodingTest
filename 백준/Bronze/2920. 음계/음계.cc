#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void){
	int * num = new int[8];
	
	for(int i = 0; i < 8; i++)
		cin>>num[i];
	
	if(num[0] == 1){ // ascending 검증
		for(int i = 0; i < 7; i++){
			if(num[i] >= num[i+1]){
				cout<<"mixed"<<endl;
				return 0;
			}
		}
		
		cout<<"ascending"<<endl;
		return 0;
	}else if(num[0] == 8){ // descending 검증
		for(int i = 0; i < 7; i++){
			if(num[i] <= num[i+1]){
				cout<<"mixed"<<endl;
				return 0;
			}
		}
		
		cout<<"descending"<<endl;
		return 0;
	}else{
		cout<<"mixed"<<endl;
		return 0;
	}
}