using System;

public class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        
        while(true)
        {
            bool isFinish = true;
            
            for(int i = 0; i < arr.Length; i++)
            {
                if(arr[i] < 50 && arr[i] % 2 == 1)
                {
                    arr[i] = arr[i] * 2 + 1;
                    isFinish = false;
                }
                else if(arr[i] > 50 && arr[i] % 2 == 0)
                {
                    arr[i] = arr[i] / 2;
                    isFinish = false;
                }
                
            }
            
            if(isFinish) break;
            
            answer++;
        }
        
        return answer;
    }
}