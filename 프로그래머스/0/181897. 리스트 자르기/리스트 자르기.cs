using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        int[] answer;
        
        int a = slicer[0];
        int b = slicer[1];
        int c = slicer[2];
        
        if(n == 1)
        {
            answer = new int[b + 1];
            Array.Copy(num_list, 0, answer, 0, b + 1);
            return answer;
        }
        else if(n == 2)
        {
            answer = new int[num_list.Count() - a];
            Array.Copy(num_list, a, answer, 0, num_list.Count() - a);
            return answer;
        }
        else if(n == 3)
        {
            answer = new int[b - a + 1];
            Array.Copy(num_list, a, answer, 0, b - a + 1);
            return answer;
        }
        else
        {
            List<int> answerList = new List<int>();
            for(int i = a; i <= b; i += c)
            {
                answerList.Add(num_list[i]);
            }
            return answerList.ToArray();
        }
    }
}