using System;

public class Solution {
    public string solution(string my_string, int[] indices) {
        char[] array = my_string.ToCharArray();
        
        foreach(int num in indices)
        {
            array[num] = '#';
        }
        
        string answer = (new string(array)).Replace("#", "");
        
        return answer;
    }
}