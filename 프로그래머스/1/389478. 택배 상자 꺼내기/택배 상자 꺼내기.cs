using System;

public class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        
        int num2 = ((num - 1) / w + 2) * w - ((num - 1) % w);
        
        for(int i = num; i <= n; i += w * 2)
        {
            answer++;
        }
        
        for(int i = num2; i <= n; i += w * 2)
        {
            answer++;
        }
        
        return answer;
    }
}