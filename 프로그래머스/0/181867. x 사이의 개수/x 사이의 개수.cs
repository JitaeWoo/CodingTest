using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string myString) {
        List<int> list = new List<int>();

        string[] inputs = myString.Split("x");

        foreach(string str in inputs)
        {
            list.Add(str.Length);
        }

        return list.ToArray();
    }
}