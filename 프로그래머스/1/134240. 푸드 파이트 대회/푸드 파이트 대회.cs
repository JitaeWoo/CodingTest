using System;
using System.Collections.Generic;

public class Solution {
    public string solution(int[] food) {
        int[] foodCount = new int[food.Length];
        List<int> result = new List<int>();
        
        for(int i = 1; i < food.Length; i++)
        {
            foodCount[i] = food[i] / 2;
        }
        
        for(int i = 1; i < foodCount.Length; i++)
        {
            for(int j = 0; j < foodCount[i]; j++)
            {
                result.Add(i);
            }
        }
        
        result.Add(0);
        
        for(int i = foodCount.Length - 1; i > 0; i--)
        {
            for(int j = 0; j < foodCount[i]; j++)
            {
                result.Add(i);
            }
        }
        
        return string.Join("", result);
    }
}