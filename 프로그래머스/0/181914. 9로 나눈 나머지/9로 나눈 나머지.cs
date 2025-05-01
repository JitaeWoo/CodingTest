using System;

public class Solution {
    public int solution(string number) {
        int answer = 0;
        
        foreach(char c in number)
        {
            answer += int.Parse(c.ToString());
        }
        
        return answer % 9;
    }
}