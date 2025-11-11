public class Solution {
    public string solution(int a, int b) {
        string[] dayStrings = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        int[] days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDay = 0;
        
        for(int i = 0; i < a - 1; i++)
        {
            totalDay += days[i];
        }
        
        totalDay += b;
        
        return dayStrings[(totalDay % 7 + 4) % 7];
    }
}