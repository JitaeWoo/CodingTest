using System;

public class Solution {
    public string solution(string s, string skip, int index) {
        char[] answer = new char[s.Length];
        
        for(int i = 0; i < s.Length; i++)
        {
            char ch = s[i];
            
            for(int j = 0; j < index; j++)
            {
                ch++;
                
                if(ch > 'z') ch = 'a';
                if(skip.Contains(ch)) j--;
            }
            
            answer[i] = ch;
        }
        
        return new string(answer);
    }
}