using System;

public class Solution {
    public int solution(int[,] board) {
        int answer = 0;
        
        for(int i = 0; i < board.GetLength(0); i++)
        {
            for(int j = 0; j < board.GetLength(1); j++)
            {
                int minX = Math.Max(0, i - 1);
                int maxX = Math.Min(board.GetLength(0) - 1, i + 1);

                int minY = Math.Max(0, j - 1);
                int maxY = Math.Min(board.GetLength(1) - 1, j + 1);

                bool isSafe = true;
                for(int k = minX; k <= maxX; k++)
                {
                    for(int l = minY; l <= maxY; l++)
                    {
                        if (board[k, l] == 1)
                        {
                            isSafe = false;
                            break;
                        }
                    }
                }

                if (isSafe)
                {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}