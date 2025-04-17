using System;

public class Solution {
    public int solution(string my_string, string is_prefix) {
        for(int i = 0; i < is_prefix.Length; i++)
        {
            if(i > my_string.Length - 1 || my_string[i] != is_prefix[i])
            {
                return 0;
            }
        }
        
        return 1;
    }
}