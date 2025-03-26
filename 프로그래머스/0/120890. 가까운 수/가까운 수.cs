using System;

public class Solution {
    public int solution(int[] array, int n) {
        int answer = 0;
        int min = int.MaxValue;
        
        foreach(int num in array)
        {
            int temp = (int)MathF.Abs(n - num);
            if(temp < min)
            {
                min = temp;
                answer = num;
            }
            else if(temp == min)
            {
                if(answer > num)
                {
                    answer = num;    
                }
            }
        }
        
        return answer;
    }
}