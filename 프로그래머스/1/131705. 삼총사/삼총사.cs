using System;

public class Solution {
    public int solution(int[] number) {
        int answer = 0;
        
        for(int i = 0; i < number.Length; i++)
        {
            for(int j = i; j < number.Length; j++)
            {
                if(i == j) continue;
                for(int k = j; k < number.Length; k++)
                {
                    if(i == k || j == k) continue;
                    
                    if(number[i] + number[j] + number[k] == 0)
                    {
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
}