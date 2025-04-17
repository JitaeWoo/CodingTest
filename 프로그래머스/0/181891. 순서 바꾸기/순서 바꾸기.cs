using System;

public class Solution {
    public int[] solution(int[] num_list, int n) {
        int[] answer = new int[num_list.Length];
        
        for(int i = 0; i < num_list.Length; i++)
        {
            if(n > num_list.Length - 1)
            {
                n = 0;
            }
            answer[i] = num_list[n];
            n++;
        }
        
        return answer;
    }
}