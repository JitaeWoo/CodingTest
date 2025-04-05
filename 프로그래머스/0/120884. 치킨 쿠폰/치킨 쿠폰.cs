using System;

public class Solution {
    public int solution(int chicken) {
        int answer = 0;
        
        int totalchicken = chicken + chicken / 10;
        int temp = 0;

        while (temp != totalchicken)
        {
            temp = totalchicken;
            totalchicken = chicken + totalchicken / 10;
        }

        answer = totalchicken - chicken;
        
        return answer;
    }
}