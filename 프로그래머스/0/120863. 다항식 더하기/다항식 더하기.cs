using System;

public class Solution {
    public string solution(string polynomial) {
        string answer = "";
        
        string[] inputs = polynomial.Split();

        string op = "+";
        int x = 0;
        int a = 0;
        for (int i = 0; i < inputs.Length; i++)
        {
            if (i % 2 == 0)
            {
                if (inputs[i].Contains("x"))
                {
                    inputs[i] = inputs[i].Replace("x", "");

                    int temp;

                    if (inputs[i] != "")
                    {
                        temp = int.Parse(inputs[i]);
                    }
                    else
                    {
                        temp = 1;
                    }

                    if (op != "+")
                    {
                        temp *= -1;
                    }

                    x += temp;
                }
                else
                {
                    int temp = int.Parse(inputs[i]);

                    if (op != "+")
                    {
                        temp *= -1;
                    }

                    a += temp;
                }
            }
        }

        string stringX = "";
        if (x == 0)
        {
            stringX = "";
        }
        else if (x == 1)
        {
            stringX = "x";
        }
        else
        {
            stringX = $"{x}x";
        }

        string stringA = "";
        if (a == 0)
        {
            stringA = "";
        }
        else if (stringX != "")
        {
            stringA = $" + {a}";
        }
        else
        {
            stringA = $"{a}";
        }

        answer = $"{stringX}{stringA}";
        
        return answer;
    }
}