public class Solution {
    public string solution(string s) {
        string answer = "";
        
        int max = int.MinValue;
        int min = int.MaxValue;
        
        string[] split = s.Split();
        
        for(int i = 0; i < split.Length; i++)
        {
            int num = int.Parse(split[i]);
            
            if(num > max)
            {
                max = num;
            }
            
            if(num < min)
            {
                min = num;
            }
        }
        
        
        return $"{min} {max}";
    }
}