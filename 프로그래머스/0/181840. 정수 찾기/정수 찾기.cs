using System;
using System.Linq;

public class Solution {
    public int solution(int[] num_list, int n) {
        if(num_list.ToList().Contains(n))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}