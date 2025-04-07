using System;

public class Solution {
    public int solution(string myString, string pat) {
        if(myString.ToUpper().Contains(pat.ToUpper()))
        {
            return 1;
        }
        
        return 0;
    }
}