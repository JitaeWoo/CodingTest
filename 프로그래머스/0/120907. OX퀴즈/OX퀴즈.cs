using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] quiz) {
        string[] answer = new string[] {};
        
        List<string> list = new List<string>();

        for (int i = 0; i < quiz.Length; i++)
        {
            string[] inputs = quiz[i].Split();

            int num1 = int.Parse(inputs[0]);
            int num2 = int.Parse(inputs[2]);
            int numResult = int.Parse(inputs[4]);

            string result = "X";
            if (inputs[1] == "+")
            {
                if(num1 + num2 == numResult)
                {
                    result = "O";
                }
            }
            else
            {
                if(num1 - num2 == numResult)
                {
                    result = "O";
                }
            }

            list.Add(result);
        }

        answer = list.ToArray();
        
        return answer;
    }
}