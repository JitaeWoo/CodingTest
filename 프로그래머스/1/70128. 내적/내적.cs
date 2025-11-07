using System;
using System.Linq;

public class Solution {
    public int solution(int[] a, int[] b) {
        int answer = a.Select((s, index) => s * b[index]).Sum();
        
        return answer;
    }
}