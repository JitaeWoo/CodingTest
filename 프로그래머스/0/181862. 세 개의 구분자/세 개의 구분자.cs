using System;

public class Solution {
    public string[] solution(string myStr) {
        char[] splits = {'a', 'b', 'c'};
        
        string[] answer = myStr.Split(splits, StringSplitOptions.RemoveEmptyEntries);
        
        if(answer.Length == 0)
        {
            return new string[] {"EMPTY"};
        }
        else
        {
            return answer;
        }
    }
}