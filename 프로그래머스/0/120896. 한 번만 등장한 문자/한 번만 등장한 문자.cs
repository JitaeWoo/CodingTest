using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string s) {
        string answer = "";
        
        int[] check = new int[26];

        foreach (char c in s)
        {
            check[((int)c) - 97]++;
        }

        List<char> result = new List<char>();

        for(int i = 0; i < check.Length; i++)
        {
            if (check[i] == 1)
            {
                result.Add((char)(i + 97));
            }
        }

        result.Sort();

        answer = new string(result.ToArray());
        
        return answer;
    }
}