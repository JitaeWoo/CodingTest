using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        int[] answer = new int[s.Length];
        Dictionary<char, int> indexDict = new Dictionary<char, int>();
        
        for(int i = 0; i < s.Length; i++)
        {
            if(indexDict.ContainsKey(s[i]))
            {
                answer[i] = i - indexDict[s[i]];
            }
            else
            {
                answer[i] = -1;
            }
            
            indexDict[s[i]] = i;
        }
        
        
        return answer;
    }
}