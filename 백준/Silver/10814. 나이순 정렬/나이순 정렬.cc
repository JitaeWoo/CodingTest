#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::ios;

class Customer{
	public:
	int age;
	string name;
	Customer(int age, string name){
		this->age = age;
		this->name = name;
	}
};

void merge(Customer * cusArray[], int first, int m, int last){
	int i = first;
	int j = m + 1;
	Customer* kArray[last - first + 1];
	int k = 0;
	
	while(i <= m && j <= last){
		if(cusArray[i]->age <= cusArray[j]->age){
			kArray[k++] = new Customer(cusArray[i]->age, cusArray[i]->name); i++;
		}
		else{
			kArray[k++] = new Customer(cusArray[j]->age, cusArray[j]->name); j++;
		}
	}
	
	if(i <= m){
		while(i <= m){
			kArray[k++] = new Customer(cusArray[i]->age, cusArray[i]->name); i++;
		}
	}else{
		while(j <= last){
			kArray[k++] = new Customer(cusArray[j]->age, cusArray[j]->name); j++;
		}
	}
	
	for(int i = 0; i < last - first + 1; i++){
		cusArray[first + i]->age = kArray[i]->age;
		cusArray[first + i]->name = kArray[i]->name;
	}
	for(int i = 0; i < last - first + 1; i++){
		delete kArray[i];
	}
	
}

void mergeSort(Customer * cusArray[], int first, int last){
	if(first < last){
		int m = (first + last) / 2;
		
		mergeSort(cusArray, first, m);
		mergeSort(cusArray, m+1, last);
		merge(cusArray, first, m, last);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	
	int age = 0;
	string name = "";
	Customer * cusArray[N];
	for(int i = 0; i < N; i++){
		cin >> age;
		cin >> name;
		cusArray[i] = new Customer(age, name);
	}
	
	mergeSort(cusArray, 0, N-1);
	
	for(int i = 0; i < N; i++){
		cout << cusArray[i]->age << " " << cusArray[i]->name << "\n";
	}
	
	return 0;
}