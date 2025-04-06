using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] strArr) {
        List<string> list = new List<string>();

        foreach(string str in strArr)
        {
            if (!str.Contains("ad"))
            {
                list.Add(str);
            }
        }

        return list.ToArray();
    }
}