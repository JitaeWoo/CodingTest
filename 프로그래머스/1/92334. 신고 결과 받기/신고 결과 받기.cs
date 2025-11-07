using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
        int[] answer = new int[id_list.Length];
        Dictionary<string, int> idToIndex = new Dictionary<string, int>();
        Dictionary<string, int> reportCount = new Dictionary<string, int>();
        Dictionary<string, List<string>> reportIds = new Dictionary<string, List<string>>();
        
        for(int i = 0; i < id_list.Length; i++)
        {
            idToIndex[id_list[i]] = i;
            reportCount[id_list[i]] = 0;
            reportIds[id_list[i]] = new List<string>();
        }
        
        foreach(string str in report)
        {
            string[] split = str.Split(' ');
            
            if(!reportIds[split[1]].Contains(split[0]))
            {
                reportCount[split[1]]++;
                reportIds[split[1]].Add(split[0]);
            }
        }
        
        for(int i = 0; i < id_list.Length; i++)
        {
            if(reportCount[id_list[i]] >= k)
            {
                foreach(string id in reportIds[id_list[i]])
                {
                    answer[idToIndex[id]]++;
                }
            }
        }
        
        return answer;
    }
}