using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] park, string[] routes) {
        int[] answer = new int[] {};
        
        Dictionary<string, int> dirToIndex = new Dictionary<string, int>();
        dirToIndex["E"] = 0;
        dirToIndex["W"] = 1;
        dirToIndex["S"] = 2;
        dirToIndex["N"] = 3;
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        int[] curPosition = {0, 0};
        
        for(int i = 0; i < park.Length; i++)
        {
            bool isCheck = false;
            
            for(int j = 0; j < park[i].Length; j++)
            {
                if(park[i][j] == 'S')
                {
                    curPosition = new int[]{i, j};
                    isCheck = true;
                    break;
                }
            }
            
            if(isCheck)
            {
                break;
            }
        }
        
        for(int i = 0; i < routes.Length; i++)
        {
            string[] commands = routes[i].Split(" ");
            
            int op = dirToIndex[commands[0]];
            int length = int.Parse(commands[1]);
            
            bool isSuccess = true;
            
            for(int j = 0; j < length; j++)
            {
                int x = curPosition[1] + (dx[op] * (j + 1));
                int y = curPosition[0] + (dy[op] * (j + 1));
                
                if(x >= park[0].Length || x < 0 
                   || y >= park.Length || y < 0
                   || park[y][x] == 'X')
                {
                    isSuccess = false;
                    break;
                }
            }
            
            if(isSuccess)
            {
                curPosition[1] += dx[op] * length;
                curPosition[0] += dy[op] * length;
            }
        }
        
        return curPosition;
    }
}