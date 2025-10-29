using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string code) {
        List<char> answer = new List<char>();
        
        int mode = 0;
        
        for(int i = 0; i < code.Length; i++)
        {
            if(code[i] == '1')
            {
                mode = mode == 0 ? 1 : 0;
                continue;
            }
            
            if(mode == 0 && i % 2 == 0)
            {
                answer.Add(code[i]);
            }
            else if(mode == 1 && i % 2 == 1)
            {
                answer.Add(code[i]);
            }
        }
        
        if(answer.Count == 0)
        {
            return "EMPTY";
        }
        else
        {
            return new string(answer.ToArray());
        }
    }
}