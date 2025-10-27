using System;

public class Solution {
    public string solution(int[] numLog) {
        string answer = "";
        
        for(int i = 0; i < numLog.Length - 1; i++)
        {
            if(numLog[i + 1] - numLog[i] == 1)
            {
                answer = $"{answer}w";
            }
            else if(numLog[i + 1] - numLog[i] == -1)
            {
                answer = $"{answer}s";
            }
            else if(numLog[i + 1] - numLog[i] == 10)
            {
                answer = $"{answer}d";
            }
            else if(numLog[i + 1] - numLog[i] == -10)
            {
                answer = $"{answer}a";
            }
        }
        
        return answer;
    }
}