using System;

public class Solution {
    public int solution(string s) {
        int answer = 0;
        
        int xNum = 0;
        int yNum = 0;
        char x = '0';
        
        for(int i = 0; i < s.Length; i++)
        {
            if(x == '0')
            {
                x = s[i];
                xNum++;
                continue;
            }
            
            if(x == s[i])
            {
                xNum++;
            }
            else
            {
                yNum++;
            }
            
            if(xNum == yNum)
            {
                answer++;
                xNum = 0;
                yNum = 0;
                x = '0';
            }
        }
        
        if(xNum != 0) answer++;
        
        return answer;
    }
}