using System;

public class Solution {
    public int[] solution(int k, int[] score) {
        int[] rank = new int[k];
        int[] answer = new int[score.Length];
        
        
        
        for(int i = 0; i < score.Length; i++)
        {
            if(rank[0] < score[i])
            {
                rank[0] = score[i];
            }
            
            Array.Sort(rank);
            
            answer[i] = rank[Math.Max(0, k - i - 1)];
        }
        
        return answer;
    }
}