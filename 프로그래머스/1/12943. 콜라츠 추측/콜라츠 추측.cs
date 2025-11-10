public class Solution {
    public int solution(int num) {
        int answer = 0;
        long longNum = num;
        
        while(answer <= 500)
        {
            if(longNum == 1)
            {
                return answer;
            }
            
            answer++;
            
            if(longNum % 2 == 0)
            {
                longNum /= 2;
            }
            else
            {
                longNum *= 3;
                longNum++;
            }
        }
        
        return -1;
    }
}