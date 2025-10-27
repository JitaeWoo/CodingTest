using System;

public class Solution {
    public string[] solution(string[] picture, int k) {
        string[] answer = new string[picture.Length * k];
        
        for(int i = 0; i < picture.Length; i++)
        {
            char[] array = new char[picture[i].Length * k];
            
            for(int j = 0; j < picture[i].Length; j++)
            {
                for(int l = 0; l < k; l++)
                {
                    array[j*k + l] = picture[i][j];
                }
            }
            
            for(int j = 0; j < k; j++)
            {
                answer[i * k + j] = new string(array);
            }
            
        }
        
        return answer;
    }
}