using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] keyinput, int[] board) {
        int[] answer = { board[0] / 2, board[1] / 2 };
        
        Dictionary<string, int> command = new Dictionary<string, int>();
        command["left"] = 0;
        command["right"] = 1;
        command["up"] = 2;
        command["down"] = 3;

        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, 1, -1 };

        foreach(string str in keyinput)
        {
            int tx = answer[0] + dx[command[str]];
            int ty = answer[1] + dy[command[str]];

            if (tx < 0 || tx >= board[0] || ty < 0 || ty >= board[1])
            {
                continue;
            }
            answer[0] = tx;
            answer[1] = ty;
        }

        answer[0] -= board[0] / 2;
        answer[1] -= board[1] / 2;
        
        return answer;
    }
}