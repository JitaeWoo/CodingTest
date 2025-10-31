using System;

public class Solution {
    public int solution(string[] babbling) {
        int answer = 0;
        
        for(int i = 0; i < babbling.Length; i++)
        {
            string str = babbling[i];
            
            if(str.IndexOf("ayaaya") != -1
              || str.IndexOf("yeye") != -1
              || str.IndexOf("mama") !=  -1
              || str.IndexOf("woowoo") != -1)
            {
                continue;
            }
            
            
            babbling[i] = babbling[i].Replace("aya", "#")
                .Replace("ye", "#")
                .Replace("woo", "#")
                .Replace("ma", "#")
                .Replace("#", "");
            
            if(babbling[i].Length == 0)
            {
                answer++;
            }
        }
        
        return answer;
    }
}