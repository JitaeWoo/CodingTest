using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int s, int e) {
        string answer = $"{my_string.Substring(0, s)}{new string(my_string.Substring(s, e - s + 1).Reverse().ToArray())}{my_string.Substring(e + 1)}";
        return answer;
    }
}