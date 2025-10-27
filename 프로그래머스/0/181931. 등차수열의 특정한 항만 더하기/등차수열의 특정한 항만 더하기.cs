using System;

public class Solution {
    public int solution(int a, int d, bool[] included) {
        int answer = 0;
        int sum = a;
        
        if(included[0])
        {
            answer += a;
        }
        
        for(int i = 1; i < included.Length; i++)
        {
            sum += d;
            if(included[i])
            {
                answer += sum;
            }
        }
        
        return answer;
    }
}