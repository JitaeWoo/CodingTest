using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        List<int> answer = arr.ToList();
        
        int maxCount = 1;
        
        while (maxCount < arr.Length)
        {
            maxCount *= 2;
        }
        
        while(answer.Count < maxCount)
        {
            answer.Add(0);
        }
        
        return answer.ToArray();
    }
}