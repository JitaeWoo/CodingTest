using System;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        string answer = "";
        
        int index1 = 0;
        int index2 = 0;
        
        for(int i = 0; i < goal.Length; i++)
        {
            if(cards1.Length > index1 && cards1[index1] == goal[i])
            {
                index1++;
                continue;
            }
            
            if(cards2.Length > index2 && cards2[index2] == goal[i])
            {
                index2++;
                continue;
            }
            
            return "No";
        }
        
        return "Yes";
    }
}