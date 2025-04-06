using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string my_string) {
        List<string> list = new List<string>();

        string[] inputs = my_string.Split();

        foreach(string str in inputs)
        {
            if(str != "")
            {
                list.Add(str);
            }
        }

        return list.ToArray();
    }
}