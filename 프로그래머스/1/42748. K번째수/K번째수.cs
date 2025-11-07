using System;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        int[] answer = new int[commands.GetLength(0)];
        
        for(int i = 0; i < commands.GetLength(0); i++)
        {
            int start = commands[i, 0];
            int end = commands[i, 1];
            int k = commands[i, 2];
            
            int[] result = new int[end - start + 1];
            
            Array.Copy(array, start - 1, result, 0, result.Length);
            Array.Sort(result);
            
            answer[i] = result[k - 1];
        }
        
        
        
        
        return answer;
    }
}