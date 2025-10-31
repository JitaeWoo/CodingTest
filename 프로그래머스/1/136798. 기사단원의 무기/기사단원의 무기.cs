using System;

public class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        
        for(int i = 1; i <= number; i++)
        {
            int num = GetDivisor(i);
            
            if(num > limit)
            {
                answer += power;
            }
            else
            {
                answer += num;
            }
        }
        
        return answer;
    }
    
    private int GetDivisor(int num)
    {
        if(num == 1) return 1;

        int result = 0;
        int sqrt = (int)Math.Sqrt(num);

        for(int i = 1; i <= sqrt; i++)
        {
            if(num % i == 0)
            {
                result++;
            }
        }

        result *= 2;

        if(sqrt * sqrt == num) result--;

        return result;
    }
}

