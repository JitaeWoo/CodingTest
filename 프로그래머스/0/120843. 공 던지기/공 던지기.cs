using System;

public class Solution {
    public int solution(int[] numbers, int k) {
        int answer = 0;
        
        int index = ((k - 1) * 2) % numbers.Length;

        answer = numbers[index];    
        
        return answer;
    }
}