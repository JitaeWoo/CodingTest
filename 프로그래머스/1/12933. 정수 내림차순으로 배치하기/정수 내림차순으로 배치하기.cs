using System;

public class Solution {
    public long solution(long n) {
        char[] array = $"{n}".ToCharArray();
        
        Array.Sort(array);
        Array.Reverse(array);
        
        return long.Parse(new string(array));
    }
}