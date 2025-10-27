using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string a, string b) {
        List<int> answer = new List<int>();
        Stack<int> aStack = new Stack<int>();
        Stack<int> bStack = new Stack<int>();
        
        foreach(char ch in a)
        {
            aStack.Push(ch - '0');
        }
        
        foreach(char ch in b)
        {
            bStack.Push(ch - '0');
        }
        
        int sum = 0;
        while(bStack.Count != 0 || aStack.Count != 0)
        {
            int aNum = 0;
            int bNum = 0;
            if(aStack.Count != 0)
            {
                aNum = aStack.Pop();
            }
            if(bStack.Count != 0)
            {
                bNum = bStack.Pop();
            }
            
            int result = aNum + bNum + sum;
            
            sum = result / 10;
            
            answer.Add(result % 10);
        }
        
        if(sum == 1)
        {
            answer.Add(1);
        }
        
        answer.Reverse();
        
        return string.Join("", answer);
    }
}