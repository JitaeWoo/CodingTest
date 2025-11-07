using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {7, 7};
        
        
        
        foreach(int num in lottos)
        {
            if(win_nums.Contains(num))
            {
                answer[0]--;
                answer[1]--;
            }
            else if(num == 0)
            {
                answer[0]--;
            }
        }
        
        for(int i = 0; i < 2; i++)
        {
            if(answer[i] > 6)
            {
                answer[i] = 6;
            }
        }
        
        return answer;
    }
}