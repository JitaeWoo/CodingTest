using System;

public class Solution {
    public int solution(int[] schedules, int[,] timelogs, int startday) {
        int answer = 0;
        
        for(int i = 0; i < schedules.Length; i++)
        {
            bool isSuccess = true;
            
            for(int j = 0; j < 7; j++)
            {
                if((startday + j) % 7 == 0 || (startday + j) % 7 == 6)
                {
                    continue;
                }
                
                int h = timelogs[i, j] / 100 - schedules[i] / 100;
                int m = timelogs[i, j] % 100 - schedules[i] % 100;
                
                if(h * 60 + m > 10)
                {
                    isSuccess = false;
                }
            }
            
            if(isSuccess)
            {
                answer++;
            }
        }
        
        return answer;
    }
}