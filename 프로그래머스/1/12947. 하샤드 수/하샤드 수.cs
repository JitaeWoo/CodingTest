public class Solution {
    public bool solution(int x) {
        int sum = 0;
        string str = $"{x}";
        
        for(int i = 0; i < str.Length; i++)
        {
            sum += str[i] - '0';
        }
        
        
        return x % sum == 0;
    }
}