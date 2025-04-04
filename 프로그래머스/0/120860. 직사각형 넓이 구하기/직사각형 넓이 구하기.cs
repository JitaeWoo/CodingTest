using System;

public class Solution {
    public int solution(int[,] dots) {
        int answer = 0;
        
        int dx = 0;
        int dy = 0;

        for(int i = 0; i < dots.GetLength(0) - 1; i++)
        {
            if (dots[i, 0] != dots[i + 1, 0])
            {
                dx = Math.Abs(dots[i, 0] - dots[i + 1, 0]);
            }

            if (dots[i, 1] != dots[i + 1, 1])
            {
                dy = Math.Abs(dots[i, 1] - dots[i + 1, 1]);
            }
        }

        answer = dx * dy;
        
        return answer;
    }
}