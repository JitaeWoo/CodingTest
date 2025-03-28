using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int n) {
        int[] answer = new int[] {};
        
        List<int> result = new List<int>();

        for(int i = 2; i <= n; i++)
        {
            if(n % i == 0)
            {
                result.Add(i);
                while(n % i == 0)
                {
                    n /= i;
                }
            }
        }

        answer = result.ToArray();
        
        return answer;
    }
}