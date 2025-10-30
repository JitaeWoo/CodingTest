using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
        Dictionary<string, int> playerIndexs = new Dictionary<string, int>();
        
        for(int i = 0; i < players.Length; i++)
        {
            playerIndexs.Add(players[i], i);
        }
        
        foreach(string call in callings)
        {
            players[playerIndexs[call]] = players[playerIndexs[call] - 1];
            players[playerIndexs[call] - 1] = call;
            
            playerIndexs[players[playerIndexs[call]]]++;
            playerIndexs[call]--;
        }
        
        return players;
    }
}