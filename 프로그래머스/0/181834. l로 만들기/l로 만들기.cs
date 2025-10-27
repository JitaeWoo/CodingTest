using System;

public class Solution {
    public string solution(string myString) {
        string answer = "";
        
        foreach(char ch in myString)
        {
            if(ch < 'l')
            {
                answer = $"{answer}l";
            }
            else
            {
                answer = $"{answer}{ch}";
            }
        }
        
        return answer;
    }
}