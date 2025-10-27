using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        
        foreach(int num in num_list)
        {
            int temp = num;
            while(temp != 1)
            {
                if(temp % 2 == 0)
                {
                    temp /= 2;
                    answer++;
                }
                else
                {
                    temp--;
                }
            }
            
        }
        
        return answer;
    }
}