using System;

public class Solution {
    public int[] solution(string[] keymap, string[] targets) {
        int[] answer = new int[targets.Length];
        
        for(int i = 0; i < targets.Length; i++)
        {
            foreach(char ch in targets[i])
            {
                int min = int.MaxValue;

                foreach(string key in keymap)
                {
                    int count = key.IndexOf(ch) + 1;
                    
                    if(count == 0) continue;
                    
                    if(min > count) min = count;
                }
                
                if(min == int.MaxValue)
                {
                    answer[i] = -1;
                    break;
                }
                else
                {
                    answer[i] += min;
                }
            }
        }
        
        return answer;
    }
}