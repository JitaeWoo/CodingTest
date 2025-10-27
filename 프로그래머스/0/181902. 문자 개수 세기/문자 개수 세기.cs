using System;

public class Solution {
    public int[] solution(string my_string) {
        int[] answer = new int[52];
        
        foreach(char ch in my_string)
        {
            int index = 0;
            if(ch > 96)
            {
                index = ch - 71;
            }
            else
            {
                index = ch - 65;
            }
            
            answer[index]++;
        }
        
        return answer;
    }
}