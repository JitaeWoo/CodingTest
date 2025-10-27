using System;

public class Solution {
    public string[] solution(string[] str_list) {
        string[] answer = {};
        
        for(int i = 0; i < str_list.Length; i++)
        {
            if(str_list[i] == "l")
            {
                answer = new string[i];
                Array.Copy(str_list, 0, answer, 0, i);
                break;
            }
            else if(str_list[i] == "r")
            {
                answer = new string[str_list.Length - i - 1];
                Array.Copy(str_list, i + 1, answer, 0, str_list.Length - i - 1);
                break;
            }
        }
        
        return answer;
    }
}