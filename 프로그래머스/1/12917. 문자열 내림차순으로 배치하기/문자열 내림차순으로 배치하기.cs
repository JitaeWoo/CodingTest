public class Solution {
    public string solution(string s) {
        char[] array = s.ToCharArray();
        
        System.Array.Sort(array);
        System.Array.Reverse(array);
        
        return new string(array);
    }
}