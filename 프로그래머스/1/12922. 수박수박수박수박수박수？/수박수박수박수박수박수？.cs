public class Solution {
    public string solution(int n) {
        char[] answer = new char[n];
        
        bool op = true;
        
        for(int i = 0; i < n; i++)
        {
            answer[i] = op ? '수' : '박';
            op = !op;
        }
        
        return new string(answer);
    }
}