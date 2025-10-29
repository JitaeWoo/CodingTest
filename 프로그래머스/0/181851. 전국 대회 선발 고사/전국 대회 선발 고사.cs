using System;
using System.Linq;

public class Solution {
    public int solution(int[] rank, bool[] attendance) {
        int answer = 0;
        
        int[] result = rank.
            Select((r, index) => new {r, index}).
            Where((r, index) => attendance[index]).
            OrderBy(r => r.r).
            Select(r => r.index).
            ToArray();
        
        answer = result[0]*10000 + result[1]*100 + result[2];
        
        return answer;
    }
}