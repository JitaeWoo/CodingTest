using System;

public class Solution {
    public int[] solution(int[] arr) {
        int first = Array.IndexOf(arr, 2);
        int end = Array.LastIndexOf(arr, 2);
        
        if(first == -1){
            return new int[]{-1};
        }
        
        int[] answer = new int[end - first + 1];
        
        for(int i = first; i <= end; i++)
        {
            answer[i - first] = arr[i];
        }
        
        return answer;
    }
}