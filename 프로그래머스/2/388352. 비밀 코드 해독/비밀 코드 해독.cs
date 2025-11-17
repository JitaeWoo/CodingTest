using System;

public class Solution {
    public int solution(int n, int[,] q, int[] ans) {
        return Func1(n, q, ans, 0, 1,  new int[5]);
    }
    
    private int Func1(int n, int[,] q, int[] ans, int index, int min, int[] query)
    {
        int result = 0;
        
        if(index == 4)
        {
            for(int i = min; i <= n; i++)
            {
                query[index] = i;
                if(Func2(q, ans, query))
                {
                    result++;
                }
            }
            
            return result;
        }
        
        for(int i = min; i <= n; i++)
        {
            query[index] = i;
            result += Func1(n, q, ans, index+1, i + 1, query);
        }
        
        return result;
    }
    
    private bool Func2(int[,] q, int[] ans, int[] query)
    {
        for(int i = 0; i < q.GetLength(0); i++)
        {
            int result = 0;
            
            for(int j = 0; j < q.GetLength(1); j++)
            {
                foreach(int num in query)
                {
                    if(num == q[i, j])
                    {
                        result++;
                        break;
                    }
                }
            }
            
            if(result != ans[i])
            {
                return false;
            }
        }
        
        return true;
    }
}