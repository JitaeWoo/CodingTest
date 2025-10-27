using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        List<int> answer = new List<int>();
        
        for(int i = 0; i < arr.Length; i++)
        {
            if(answer.Count() == 0)
            {
                answer.Add(arr[i]);
            }
            else if(answer.Last() == arr[i])
            {
                answer.RemoveAt(answer.Count() - 1);
            }
            else
            {
                answer.Add(arr[i]);
            }
            
        }
        
        if(answer.Count() == 0)
        {
            return new int[]{-1};
        }
        else
        {
            return answer.ToArray();
        }
    }
}