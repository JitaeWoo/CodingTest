using System;

public class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        int temp;

        if (num % 2 == 0)
        {
            temp = total / (num / 2);
            temp /= 2;
            temp -= num / 2 - 1;
        }
        else
        {
            temp = total / num;
            temp -= num / 2;
        }
        for (int i = 0; i < answer.Length; i++)
        {
            answer[i] = temp;
            temp++;
        }
        return answer;
    }
}