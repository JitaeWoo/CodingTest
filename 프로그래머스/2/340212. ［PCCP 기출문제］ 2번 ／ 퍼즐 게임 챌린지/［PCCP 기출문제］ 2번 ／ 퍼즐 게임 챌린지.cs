using System;

public class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        int op = 1000;
        
        while(op != 0)
        {
            answer += op;
            
            if(Func1(diffs, times, answer) <= limit)
            {
                answer -= op;
                op /= 10;
            }
        }
        answer++;
        
        return answer;
    }
    
    private long Func1(int[] diffs, int[] times, int level)
    {
        long totalTime = 0;
        
        for(int i = 0; i < diffs.Length; i++)
        {
            if(diffs[i] > level)
            {    
                totalTime += (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
            }
            else
            {
                totalTime += times[i];
            }
        }
        
        return totalTime;
    }
}