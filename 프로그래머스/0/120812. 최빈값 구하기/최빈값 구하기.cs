using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] array) {
        int answer = 0;
        
        Dictionary<int, int> dic = new Dictionary<int, int>();

        foreach(int num in array)
        {
            if (dic.ContainsKey(num))
            {
                dic[num]++;
            }
            else
            {
                dic[num] = 1;
            }
        }

        int max = 0;
        foreach(KeyValuePair<int, int> item in dic)
        {
            if(max < item.Value)
            {
                answer = item.Key;
                max = item.Value;
            }
            else if(max == item.Value)
            {
                answer = -1;
            }
        }
        
        return answer;
    }
}