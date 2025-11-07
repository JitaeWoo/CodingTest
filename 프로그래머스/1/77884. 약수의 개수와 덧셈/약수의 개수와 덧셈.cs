using System;

public class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int i = left; i <= right; i++)
        {
            int num = (int)Math.Sqrt(i);
            double fNum = Math.Sqrt(i);
            
            if((double)num == fNum)
            {
                answer -= i;
            }
            else
            {
                answer += i;
            }
        }
        
        
        return answer;
    }
}