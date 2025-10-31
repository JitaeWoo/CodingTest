using System;

public class Solution {
    public int[] solution(string[] wallpaper) {
        int lux = int.MaxValue;
        int luy = int.MaxValue;
        int rdx = 0;
        int rdy = 0;
        
        for(int i = 0; i < wallpaper.Length; i++)
        {
            for(int j = 0; j < wallpaper[i].Length; j++)
            {
                if(wallpaper[i][j] != '#') continue;
                
                if(luy > j) luy = j;
                if(lux > i) lux = i;
                if(rdy < j) rdy = j;
                if(rdx < i) rdx = i;
            }
        }
        
        rdx++;
        rdy++;
        
        return new int[]{lux, luy, rdx, rdy};
    }
}