using System;

public class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        int num1 = a;
        int num2 = b;

        while (num1 % num2 != 0)
        {
            int temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }

        b /= num2;

        for(int i = 3; i <= b; i++)
        {
            if(i % 2 == 0 || i % 5 == 0)
            {
                continue;
            }

            if(b % i == 0)
            {
                return 2;
            }
        }

        return 1;
    }
}