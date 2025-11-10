public class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        int nNum = n;
        int mNum = m;
        
        while(nNum % mNum != 0)
        {
            int temp = mNum;
            mNum = nNum % mNum;
            nNum = temp;
        }
        
        answer[0] = mNum;
        answer[1] = n * m / mNum;
        
        
        return answer;
    }
}