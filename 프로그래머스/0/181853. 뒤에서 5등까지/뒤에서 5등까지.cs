using System;

public class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[5];

        Array.Sort(num_list);

        Array.Copy(num_list, 0, answer, 0, 5);
        return answer;
    }
}