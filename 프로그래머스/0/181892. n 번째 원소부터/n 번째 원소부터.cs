using System;

public class Solution {
    public int[] solution(int[] num_list, int n) {
        
        int length = num_list.Length;
        
        int[] answer = new int[length - n + 1];
        
        for(int i = 0; i < length - n + 1; i++)
        {
            answer[i] = num_list[n + i - 1];
        }
        return answer;
    }
}