using System;

public class Solution {
    public string solution(string[] survey, int[] choices) {
        char[] answer = new char[4];
        int[] result = new int[4];
        
        for(int i = 0; i < survey.Length; i++)
        {
            int op = 1;
            int index = 0;
            
            if(survey[i][0] == 'R' || survey[i][0] == 'T')
            {
                index = 0;
            }
            else if(survey[i][0] == 'C' || survey[i][0] == 'F')
            {
                index = 1;
            }
            else if(survey[i][0] == 'J' || survey[i][0] == 'M')
            {
                index = 2;
            }
            else if(survey[i][0] == 'A' || survey[i][0] == 'N')
            {
                index = 3;
            }
            
            if(survey[i][0] == 'T' || survey[i][0] == 'F' || survey[i][0] == 'M' || survey[i][0] == 'N')
            {
                op = -1;
            }
            
            result[index] += (choices[i] - 4) * op;
        }
        
        char[,] Indicator = 
        {
            {'R', 'C', 'J', 'A'},
            {'T', 'F', 'M', 'N'}
        };
        
        for(int i = 0; i < 4; i++)
        {
            answer[i] = Indicator[result[i] <= 0 ? 0 : 1, i];
        }
        
        return new string(answer);
    }
}