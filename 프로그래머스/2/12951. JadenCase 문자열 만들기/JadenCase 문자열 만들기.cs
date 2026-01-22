using System.Text;

public class Solution {
    public string solution(string s) {
        StringBuilder answer = new StringBuilder();
        
        string[] split = s.Split();
        
        StringBuilder temp = new StringBuilder();
        foreach(string str in split)
        {
            if(string.IsNullOrEmpty(str))
            {
                answer.Append(str);
                answer.Append(" ");
                continue;
            }
            
            temp.Append(str.ToLower());
            
            if(char.IsLower(temp[0]))
            {
                temp[0] = (char)(temp[0] - 32);
            }
            
            answer.Append(temp.ToString());
            answer.Append(" ");
            
            temp.Clear();
        }
        
        answer.Remove(answer.Length - 1, 1);
        
        return answer.ToString();
    }
}