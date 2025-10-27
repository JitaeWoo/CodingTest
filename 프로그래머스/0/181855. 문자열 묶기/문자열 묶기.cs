using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] strArr) {
        int answer = 0;
        
        Dictionary<int, int> dict = new Dictionary<int, int>();
        
        foreach(string str in strArr)
        {
            int length = str.Length;
            
            if(dict.ContainsKey(length))
            {
                dict[length]++;
            }
            else{
                dict[length] = 1;
            }
        }
        
        foreach(var v in dict)
        {
            if(answer < v.Value)
            {
                answer = v.Value;
            }
        }
        
        return answer;
    }
}