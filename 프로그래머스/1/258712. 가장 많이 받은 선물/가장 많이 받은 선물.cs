using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] friends, string[] gifts) {
        int answer = 0;
        
        Dictionary<string, Friend> friendDict = new Dictionary<string, Friend>();
        
        foreach(string name in friends)
        {
            friendDict.Add(name, new Friend());
        }
        
        foreach(string gift in gifts)
        {
            string[] giftStr = gift.Split(" ");
            
            friendDict[giftStr[0]].AddGiftCount(giftStr[1]);
            friendDict[giftStr[1]].ReceiveCount++;
        }
        
        int max = 0;
        
        foreach(string name in friends)
        {
            int count = 0;
            
            foreach(string name2 in friends)
            {
                if(name == name2) continue;
                
                int count1 = friendDict[name].GetGiftCount(name2);
                int count2 = friendDict[name2].GetGiftCount(name);
                
                if(count1 > count2)
                {
                    count++;
                    continue;
                }
                
                if(count1 < count2) continue;
                
                if(friendDict[name].GiftPoint > friendDict[name2].GiftPoint)
                {
                    count++;
                }
            }
            
            if(max < count)
            {
                max = count;
            }
        }
        
        return max;
    }
}

public class Friend
{
    public Dictionary<string, int> GiftCounts = new Dictionary<string, int>();
    
    private int _giveCount = 0;
    public int ReceiveCount = 0;
    
    public int GiftPoint => _giveCount - ReceiveCount;
    
    public void AddGiftCount(string name)
    {
        if(GiftCounts.ContainsKey(name))
        {
            GiftCounts[name]++;
        }
        else
        {
            GiftCounts[name] = 1;
        }
        
        _giveCount++;
    }
    
    public int GetGiftCount(string name)
    {
        if(GiftCounts.ContainsKey(name))
        {
            return GiftCounts[name];
        }
        
        return 0;
    }
}