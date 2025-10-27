using System;

public class Solution {
    public int solution(string myString, string pat) {
        string str = "";
        
        foreach(char ch in myString)
        {
            if(ch == 'A')
            {
                str = $"{str}B";
            }
            else
            {
                str = $"{str}A";
            }
        }
        
        if(str.Contains(pat))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}