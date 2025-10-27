using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] intStrs, int k, int s, int l) {
        List<int> answer = new List<int>();
        
        foreach(string str in intStrs)
        {
            int num = int.Parse(str.Substring(s, l));
            
            if(num > k)
            {
                answer.Add(num);
            }
        }
        
        return answer.ToArray();
    }
}