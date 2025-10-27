using System;

public class Solution {
    public int solution(string binomial) {
        int answer = 0;
        
        string[] sp = binomial.Split();
        
        if(sp[1] == "+")
        {
            answer = int.Parse(sp[0]) + int.Parse(sp[2]);
        }
        else if(sp[1] == "-")
        {
            answer = int.Parse(sp[0]) - int.Parse(sp[2]);
        }
        else
        {
            answer = int.Parse(sp[0]) * int.Parse(sp[2]);
        }
        
        return answer;
    }
}