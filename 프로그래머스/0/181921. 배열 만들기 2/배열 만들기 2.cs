using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int l, int r) {
        List<int> answer = new List<int>();
        
        for(int i = l; i <= r;)
        {
            int num = i;
            
            bool isSelect = true;
            
            while(num > 0)
            {
                if(num % 5 == 0)
                {
                    num /= 10;
                }
                else
                {
                    isSelect = false;
                    break;
                }
            }
            
            if(isSelect)
            {
                answer.Add(i);
                i += 5;
            }
            else
            {
                i++;
            }
        }
        
        if(answer.Count == 0)
        {
            answer.Add(-1);
        }
        
        return answer.ToArray();
    }
}