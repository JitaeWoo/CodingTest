using System;

public class Solution {
    public int[] solution(long n) {
        char[] array = $"{n}".ToCharArray();
        
        Array.Reverse(array);
        
        int[] answer = new int[array.Length];
        
        for(int i = 0; i < answer.Length; i++)
        {
            answer[i] = array[i] - '0';
        }
        
        return answer;
    }
}