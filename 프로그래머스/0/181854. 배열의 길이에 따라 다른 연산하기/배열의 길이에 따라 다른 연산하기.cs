using System;

public class Solution {
    public int[] solution(int[] arr, int n) {
        int[] answer = arr;

        if(answer.Length % 2 == 0)
        {
            for(int i = 1; i < answer.Length; i += 2)
            {
                answer[i] += n;
            }
        }
        else
        {
            for (int i = 0; i < answer.Length; i += 2)
            {
                answer[i] += n;
            }
        }
        return answer;
    }
}