using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long sum = 0;
        long result = 0;
        
        for(int i = 1; i <= count; i++)
        {
            sum += price * i;
        }
        
        result = sum - money;
        
        if(result < 0) result = 0;
        
        return result;
    }
}