using System;

class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;

        for(int i = 0; i < nums.Length; i++)
            for(int j = i + 1; j < nums.Length; j++)
                for(int k = j + 1; k < nums.Length; k++)
                {
                    int num = nums[i] + nums[j] + nums[k];
                    bool isSuccess = true;
                    for(int l = 2; l <= Math.Sqrt(num); l++)
                    {
                        if(num % l == 0)
                        {
                            isSuccess = false;
                            break;
                        }
                    }
                    
                    if(isSuccess)
                    {
                        answer++;
                    }
                }

        return answer;
    }
}