using System;

public class Solution {
    public string solution(string s) {
        char[] answer = new char[s.Length];
        
        bool isUpper = true;
        for(int i = 0; i < answer.Length; i++)
        {
            if(s[i] == ' ')
            {
                isUpper = true;
                answer[i] = ' ';
                continue;
            }
            
            if(isUpper)
            {
                answer[i] = Char.ToUpper(s[i]);
            }
            else
            {
                answer[i] = Char.ToLower(s[i]);
            }
            
            isUpper = !isUpper;
        }
        
        return new string(answer);
    }
}