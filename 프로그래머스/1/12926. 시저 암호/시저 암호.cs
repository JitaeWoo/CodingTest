public class Solution {
    public string solution(string s, int n) {
        char[] answer = new char[s.Length];
        
        for(int i = 0; i < answer.Length; i++)
        {
            if(s[i] == ' ')
            {
                answer[i] = ' ';
                continue;
            }
            
            if(s[i] < 'a')
            {
                int temp = s[i] + n;
                answer[i] = (char)(temp > 'Z' ? temp - ('Z' - 'A' + 1) : temp);
            }
            else
            {
                int temp = s[i] + n;
                answer[i] = (char)(temp > 'z' ? temp - ('z' - 'a' + 1) : temp);
            }
        }
        
        
        return new string(answer);
    }
}