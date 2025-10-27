using System;

public class Solution {
    public int solution(string ineq, string eq, int n, int m) {
        
        if(ineq == ">" && n > m) return 1;
        if(ineq == "<" && n < m) return 1;
        if(eq == "=" && n == m) return 1;
        
        return 0;
    }
}