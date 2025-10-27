using System;

public class Solution {
    public int solution(string my_string, string is_suffix) {
        for(int i = 0; i < my_string.Length; i++)
        {
            if(my_string.Substring(i) == is_suffix)
            {
                return 1;
            }
        }
        
        return 0;
    }
}