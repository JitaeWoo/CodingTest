using System;

public class Solution {
    public int solution(string[] babbling) {
        int answer = 0;
        
        for(int i = 0; i < babbling.Length; i++)
        {
            string temp = babbling[i].Replace("aya", " ")
                .Replace("ye", " ")
                .Replace("woo", " ")
                .Replace("ma", " ")
                .Replace(" ", "");

            if(temp == "")
            {
                answer++;
            }
        }
        
        return answer;
    }
}