using System;

public class Solution {
    public int solution(string s) {
        int answer = 0;
        
        string[] inputs = s.Split();

        int num = 0;

        foreach(string str in inputs)
        {
            if(str != "Z")
            {
                num = int.Parse(str);
                answer += num;
            }
            else
            {
                answer -= num;
            }
        }
        
        return answer;
    }
}