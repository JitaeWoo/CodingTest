using System;
using System.Collections.Generic;

public struct NearNum : IComparable<NearNum>
{
    public int baseline;
    public int value;

    public NearNum(int baseline, int value)
    {
        this.baseline = baseline;
        this.value = value;
    }

    int IComparable<NearNum>.CompareTo(NearNum other)
    {
        int diffThis = Math.Abs(baseline - value);
        int diffOther = Math.Abs(baseline - other.value);

        if(diffOther == diffThis)
        {
            return other.value - value;
        }
        else
        {
            return  diffThis - diffOther;
        }
    }
}


public class Solution {
    public int[] solution(int[] numlist, int n) {
        int[] answer = new int[numlist.Length];

        List<NearNum> list = new List<NearNum>();

        for(int i = 0; i < numlist.Length; i++)
        {
            list.Add(new NearNum(n, numlist[i]));
        }

        list.Sort();

        for(int i = 0; i < numlist.Length; i++)
        {
            answer[i] = list[i].value;
        }
        
        return answer;
    }
}