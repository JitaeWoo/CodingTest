using System;

public class Solution {
    public int solution(string A, string B) {
        int answer = 0;
        
        for(int i = 0; i < A.Length; i++)
        {
            if(A == B)
            {
                break;
            }
            answer++;

            string temp = $"{A[A.Length - 1]}";

            for(int j = 0; j < A.Length - 1; j++)
            {
                temp = $"{temp}{A[j]}";
            }

            A = temp;
        }

        if(A == B)
        {
            return answer;
        }
        else
        {
            return -1;
        }
        
        return answer;
    }
}