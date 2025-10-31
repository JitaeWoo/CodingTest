using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string today, string[] terms, string[] privacies) {
        List<int> answer = new List<int>();
        
        Dictionary<string, int> termDict = new Dictionary<string, int>();
        foreach(string term in terms)
        {
            string[] array = term.Split();
            
            termDict[array[0]] = int.Parse(array[1]);
        }
        
        for(int i = 0; i < privacies.Length; i++)
        {
            string[] array = privacies[i].Split();
            
            if(GetDayDiff(today, array[0]) >= termDict[array[1]] * 28)
            {
                answer.Add(i + 1);
            }
        }
        
        return answer.ToArray();
    }
    
    private int GetDayDiff(string date1, string date2)
    {
        string[] array1 = date1.Split('.');
        string[] array2 = date2.Split('.');
        
        int y = int.Parse(array1[0]) - int.Parse(array2[0]);
        int m = int.Parse(array1[1]) - int.Parse(array2[1]);
        int d = int.Parse(array1[2]) - int.Parse(array2[2]);
        
        return y * 28 * 12 + m * 28 + d;
    }
}