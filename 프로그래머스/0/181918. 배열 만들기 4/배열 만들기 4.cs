using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        
        
        List<int> stk = new List<int>();
        
        for(int i = 0; i < arr.Length; i++)
        {
            if(stk.Count() == 0)
            {
                stk.Add(arr[i]);
            }
            else if(stk.Last() < arr[i])
            {
                stk.Add(arr[i]);
            }
            else
            {
                stk.RemoveAt(stk.Count() - 1);
                i--;
            }
        }
        
        return stk.ToArray();
    }
}