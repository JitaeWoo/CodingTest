using System;

public class Solution {
    public int solution(int[] players, int m, int k) {
        int[] timeOut = new int[50];
        int curServerCount = 0;
        
        int answer = 0;
        
        for(int i = 0; i < players.Length; i++)
        {
            curServerCount -= timeOut[i];
            
            int serverCount = players[i] / m - curServerCount;
            
            if(serverCount > 0)
            {
                answer += serverCount;
                curServerCount += serverCount;
                timeOut[i + k] += serverCount;
            }
        }
        
        return answer;
    }
}