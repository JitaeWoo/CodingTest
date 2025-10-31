using System;

public class Solution {
    public int solution(string t, string p) {
        int answer = 0;
        
        long pNum = long.Parse(p);
        
        for(int i = 0; i < t.Length - p.Length + 1; i++)
        {
            long tNum = long.Parse(t.Substring(i, p.Length));
            
            if(tNum <= pNum) answer++;
        }
        
        return answer;
    }
}