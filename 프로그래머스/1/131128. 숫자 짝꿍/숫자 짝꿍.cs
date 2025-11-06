using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string X, string Y) {
        List<char> answer = new List<char>();
        int[] XNumCounts = new int[10];
        int[] YNumCounts = new int[10];
        
        
        foreach(char ch in X)
        {
            for(int i = 0; i < 10; i++)
            {
                if(ch - '0' == i)
                {
                    XNumCounts[i]++;
                    break;
                }
            }
        }
        
        foreach(char ch in Y)
        {
            for(int i = 0; i < 10; i++)
            {
                if(ch - '0' == i)
                {
                    YNumCounts[i]++;
                    break;
                }
            }
        }
        
        for(int i = 9; i >= 0; i--)
        {
            for(int j = 0; j < XNumCounts[i] && j < YNumCounts[i]; j++)
            {
                if(i == 0 && answer.Count == 0
                  && XNumCounts[i] > 0 && YNumCounts[i] > 0)
                {
                    return "0";
                }
                
                answer.Add((char)('0' + i));
            }
        }
        
        if(answer.Count == 0)
        {
            return "-1";
        }
        else
        {
            return new string(answer.ToArray());
        }
    }
}