using System;

public class Solution {
    public int[,] solution(int n) {
        int[,] answer = new int[n, n];
        
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        
        int op = 0;
        int x = 0;
        int y = 0;
        
        for(int i = 1; i <= n*n; i++)
        {
            answer[y, x] = i;
            
            if(x + dx[op] >= n || x + dx[op] < 0
              || y + dy[op] >= n || y + dy[op] < 0
              || answer[y + dy[op], x + dx[op]] != 0)
            {
                op = (op + 1) % 4;
            }
            
            x += dx[op];
            y += dy[op];
        }
        
        return answer;
    }
}