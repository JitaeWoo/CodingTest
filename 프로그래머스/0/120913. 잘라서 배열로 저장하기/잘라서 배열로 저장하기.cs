using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string my_str, int n) {
        string[] answer = new string[] {};
        
        List<string> result = new List<string>();

        string temp = "";
        int i = 0;
        foreach(char c in my_str)
        {
            temp += c;

            i++;
            if(i == n)
            {
                result.Add(temp);
                temp = "";
                i = 0;
            }
        }

        if(temp != "")
        {
            result.Add(temp);
        }
        

        answer = result.ToArray();
        
        return answer;
    }
}