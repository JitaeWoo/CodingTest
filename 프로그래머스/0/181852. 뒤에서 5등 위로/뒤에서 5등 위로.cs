using System;

public class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[num_list.Length - 5];

        Array.Sort(num_list);

        Array.Copy(num_list, 5, answer, 0, num_list.Length - 5);
        return answer;
    }
}