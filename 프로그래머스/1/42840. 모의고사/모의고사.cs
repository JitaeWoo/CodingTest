using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] answers) {
        int[] result = new int[3];
        
        int[] answer1 = {1,2,3,4,5};
        int[] answer2 = {2,1,2,3,2,4,2,5};
        int[] answer3 = {3,3,1,1,2,2,4,4,5,5};
        
        for(int i = 0; i < answers.Length; i++)
        {
            if(answer1[i % answer1.Length] == answers[i])
            {
                result[0]++;
            }
            
            if(answer2[i % answer2.Length] == answers[i])
            {
                result[1]++;
            }
            
            if(answer3[i % answer3.Length] == answers[i])
            {
                result[2]++;
            }
        }
        
        int max = result.Max();
        
        List<int> answer = new List<int>();
        
        for(int i = 0; i < result.Length; i++)
        {
            if(max == result[i])
            {
                answer.Add(i + 1);
            }
        }
        
        return answer.ToArray();
    }
}