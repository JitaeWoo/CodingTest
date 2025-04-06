using System;

public class Solution {
    public int solution(int[,] dots) {
        if (GetSlope(dots[0, 0], dots[0, 1], dots[1, 0], dots[1, 1])
            == GetSlope(dots[2, 0], dots[2, 1], dots[3, 0], dots[3, 1]))
        {
            return 1;
        }

        if (GetSlope(dots[0, 0], dots[0, 1], dots[2, 0], dots[2, 1])
            == GetSlope(dots[3, 0], dots[3, 1], dots[1, 0], dots[1, 1]))
        {
            return 1;
        }

        if (GetSlope(dots[0, 0], dots[0, 1], dots[3, 0], dots[3, 1])
            == GetSlope(dots[1, 0], dots[1, 1], dots[2, 0], dots[2, 1]))
        {
            return 1;
        }
        
        return 0;
    }
    
    public static float GetSlope(int x1, int y1, int x2, int y2)
    {
        return (float)(y1 - y2) / (x1 - x2);
    }
}