using System;

public class Solution {
    private int[] _dp;
    
    public int solution(int[,] info, int n, int m) {
        int answer = int.MaxValue;
        _dp = new int[m];
        
        for(int i = 1; i < _dp.Length; i++)
        {
            _dp[i] = int.MaxValue;
        }
        
        for(int i = 0; i < info.GetLength(0); i++)
        {
            int num1 = info[i, 0];
            int num2 = info[i, 1];
            
            for(int j = _dp.Length - 1; j >= 0; j--)
            {
                int min = int.MaxValue;
                
                if(j - num2 >= 0 && _dp[j - num2] != int.MaxValue)
                {
                    min = _dp[j - num2];
                }
                
                if(_dp[j] == int.MaxValue)
                {
                    _dp[j] = min;
                }
                else
                {
                    _dp[j] = Math.Min(min, _dp[j] + num1);
                }
            }
        }
        
        for(int i = 0; i < _dp.Length; i++)
        {
            if(answer > _dp[i])
            {
                answer = _dp[i];
            }
        }
        
        if(answer >= n)
        {
            return -1;
        }
        
        return answer;
    }
}