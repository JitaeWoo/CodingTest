using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        int op = 1;
        List<int> temp = new List<int>();
        
        while(n != 0)
        {
            temp.Add(n % 3);
            n /= 3;
        }
        
        temp.Reverse();
        
        
        for(int i = 0; i < temp.Count; i++)
        {
            answer += (op) * temp[i];
            op *= 3;
        }
        
        return answer;
    }
}