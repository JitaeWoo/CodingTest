using System;

public class Solution {
    public string solution(string bin1, string bin2) {
        string answer = "";
        
        int sum = Convert.ToInt32(bin1, 2) + Convert.ToInt32(bin2, 2);

        answer = Convert.ToString(sum, 2);
        
        return answer;
    }
}