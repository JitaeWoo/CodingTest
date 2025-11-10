public class Solution {
    public string solution(string phone_number) {
        char[] answer = new char[phone_number.Length];
        
        for(int i = 0; i < answer.Length; i++)
        {
            if(answer.Length - i <= 4)
            {
                answer[i] = phone_number[i];
            }
            else
            {
                answer[i] = '*';
            }
        }
        
        return new string(answer);
    }
}