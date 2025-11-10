using System;

public class Solution {
    public long solution(long n) {
        long answer = 0;
        
        double num1 = Math.Sqrt(n);
        long num2 = (long)num1;
        
        if(num1 == num2)
        {
            return (num2 + 1) * (num2 + 1);
        }
        else
        {
            return -1;
        }
    }
}