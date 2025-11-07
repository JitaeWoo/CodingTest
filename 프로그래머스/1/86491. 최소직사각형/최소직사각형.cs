using System;

public class Solution {
    public int solution(int[,] sizes) {
        int big = 0;
        int small = 0;
        
        for(int i = 0; i < sizes.GetLength(0); i++)
        {
            int bigT = Math.Max(sizes[i, 0], sizes[i, 1]);
            int smallT = Math.Min(sizes[i, 0], sizes[i, 1]);
            
            if(big < bigT) big = bigT;
            if(small < smallT) small = smallT;
        }
        
        return big * small;
    }
}