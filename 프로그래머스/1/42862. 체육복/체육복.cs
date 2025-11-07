using System;
using System.Linq;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.Length + lost.Where(w => reserve.Contains(w)).Count();
        
        Array.Sort(lost);
        Array.Sort(reserve);
        
        foreach(int num in lost)
        {
            if(reserve.Contains(num)) continue;
            
            for(int i = 0; i < reserve.Length; i++)
            {
                if(lost.Contains(reserve[i]) || reserve[i] == -1) continue;
                
                if(reserve[i] == num -1 || reserve[i] == num + 1)
                {
                    reserve[i] = -1;
                    answer++;
                    break;
                }
            }
        }
        
        return answer;
    }
}