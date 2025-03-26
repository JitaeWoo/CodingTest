using System;

public class Solution {
    public int solution(string my_string) {
        int answer = 0;
        string temp = "";
        int num;
        
        foreach(char c in my_string)
        {
            if(c >= '0' && c <= '9')
            {
                temp += c;
            }
            else
            {
                if(int.TryParse(temp, out num))
                {
                    answer += num;
                }
                temp = "";
            }
        }
        
        if (int.TryParse(temp, out num))
        {
            answer += num;
        }
        
        return answer;
    }
}