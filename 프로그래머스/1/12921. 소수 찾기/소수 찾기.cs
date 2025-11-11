public class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] array = new int[n + 1];
        
        for(int i = 2; i <= n; i++)
        {
            if(array[i] == 0)
            {
                answer++;
                for(int j = i; j <= n; j += i)
                {
                    array[j] = 1;
                }
            }
        }
        
        return answer;
    }
}