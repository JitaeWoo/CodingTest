using System;

public class Solution {
    public int solution(string my_string) {
        int answer = 0;
        
        string[] inputs = my_string.Split();

        int num = 0;
        string op = "+";
        foreach(string str in inputs)
        {
            if((int.TryParse(str, out num)))
            {
               if(op == "+")
                {
                    answer += num;
                }
                else
                {
                    answer -= num;
                }
            }
            else
            {
                op = str;
            }
        }
        
        return answer;
    }
}