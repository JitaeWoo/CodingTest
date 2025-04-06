using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr1, int[] arr2) {
        if(arr1.Length > arr2.Length)
        {
            return 1;
        }
        else if(arr2.Length > arr1.Length)
        {
            return -1;
        }

        if(arr1.Sum() > arr2.Sum())
        {
            return 1;
        }
        else if (arr2.Sum() > arr1.Sum())
        {
            return -1;
        }

        return 0;
    }
}