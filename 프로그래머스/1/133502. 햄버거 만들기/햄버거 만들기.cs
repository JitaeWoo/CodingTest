using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        Stack<int> stack = new Stack<int>();
        int[] goal = {1, 3, 2 ,1};
        
        for(int i = 0; i < ingredient.Length; i++)
        {
            stack.Push(ingredient[i]);
            
            if(stack.Count >= 4 && stack.Peek() == 1)
            {
                int[] top = stack.Take(4).ToArray();
                bool isGoal = true;
                
                for(int j = 0; j < 4; j++)
                {
                    if(goal[j] != top[j])
                    {
                        
                        isGoal = false;
                        break;
                    }
                }
                
                if(isGoal)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        stack.Pop();
                    }
                    answer++;
                }
            }
        }
        
        return answer;
    }
}