using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        List<int> list = new List<int>();

        for(int i = 0; i < arr.Length; i++)
        {
            bool isAdd = true;
            foreach(int delete in delete_list)
            {
                if(delete == arr[i])
                {
                    isAdd = false;
                }
            }

            if (isAdd)
            {
                list.Add(arr[i]);
            }
        }

        return list.ToArray();
    }
}