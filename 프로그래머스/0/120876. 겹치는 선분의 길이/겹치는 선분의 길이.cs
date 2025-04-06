using System;

public class Solution {
    public int solution(int[,] lines) {
        int answer = 0;
        
        int[] check = new int[200];

        for(int i = 0; i < lines.GetLength(0); i++)
        {
            for(int j = lines[i, 0] + 100; j < lines[i, 1] + 100; j++)
            {
                if (check[j] == 0)
                {
                    check[j]++;
                }
                else if (check[j] == 1)
                {
                    check[j]++;
                    answer++;
                }
            }
        }
        
        return answer;
    }
}