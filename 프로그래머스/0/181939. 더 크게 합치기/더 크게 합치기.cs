using System;

public class Solution {
    public int solution(int a, int b) {
        int num1 = int.Parse($"{a}{b}");
        int num2 = int.Parse($"{b}{a}");
        
        int answer = num1 > num2 ? num1 : num2;
        
        return answer;
    }
}