using System;

public class Solution {
    public string solution(string myString, string pat) {
        string answer = "";
        
        for(int i = 0; i < myString.Length; i++)
        {
            string str = myString.Substring(0, myString.Length - i);
            if(str.EndsWith(pat))
            {
                return str;
            }
        }
        
        return answer;
    }
}