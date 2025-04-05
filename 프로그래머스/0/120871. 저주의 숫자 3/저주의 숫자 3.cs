using System;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        
        int num = 0;
        for(int i = 1; i <= n; i++)
        {
            num++;

            string str = num.ToString();

            bool isThree = str.Contains('3');
            while (isThree || num % 3 == 0)
            {
                num++;
                str = num.ToString();
                isThree = str.Contains('3');
            }
        }

        answer = num;
        
        return answer;
    }
}