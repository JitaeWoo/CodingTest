using System;

public class Solution {
    public int[,] solution(int[,] arr) {
        int height = arr.GetLength(0);
        int width = arr.GetLength(1);
        
        int length = height > width ? height : width;
        
        int[,] answer = new int[length, length];
        
        for(int i = 0; i < arr.GetLength(0); i++)
        {
            for(int j = 0; j < arr.GetLength(1); j++)
            {
                answer[i,j] = arr[i,j];
            }
        }
        
        
        
        
        
        return answer;
    }
}