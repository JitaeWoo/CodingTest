#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ios;
using std::string;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "", bomb = "";
    cin >> str >> bomb;
	
	
    int stack[1000002]={};
    int idx = -1, count = 0;
    string result = "";
    for(int i = 0; i < str.length(); i++){\
		if(str[i] == bomb[count]){\
            stack[++idx] = count;
            count++;
        }else if(str[i] == bomb[0]){
            stack[++idx] = 0;
            count = 1;
        }else{
			for(int j = 0; j <= idx; j++){
				result += bomb[stack[j]];
			}
			idx = -1;
			count = 0;
            result += str[i];
        }
        
        if(count >= bomb.length()){
            idx -= bomb.length();
            if(idx != -1){
                count = stack[idx]+1;
            }else{
                count = 0;
            }
        }
    }
	for(int i = 0; i <= idx; i++){
		result += bomb[stack[i]];
	}
    if(result.empty()){
        cout << "FRULA\n";
    }else{
        cout << result << "\n";
    }
    
    return 0;
}