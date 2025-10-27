using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, int k) {
        List<int> answer = new List<int>();
        
        foreach(int num in arr)
        {
            if(!answer.Contains(num))
            {
                answer.Add(num);
            }
            
            if(answer.Count >= k) break;
        }
        
        while(answer.Count < k)
        {
            answer.Add(-1);
        }
        
        return answer.ToArray();
    }
}