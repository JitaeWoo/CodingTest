using System;

public class Solution {
    public string solution(string video_len, string pos, string op_start, string op_end, string[] commands) {
        string answer = "";
        
        int videoTime = StringToTime(video_len);
        int posTime = StringToTime(pos);
        int opStartTime = StringToTime(op_start);
        int opEndTime = StringToTime(op_end);
        
        if(posTime >= opStartTime && posTime <= opEndTime)
        {
            posTime = opEndTime;
        }
        
        foreach(string command in commands)
        {
            if(command == "next")
            {
                posTime += 10;
                if(posTime > videoTime)
                {
                    posTime = videoTime;
                }
            }
            else
            {
                posTime -= 10;
                if(posTime < 0)
                {
                    posTime = 0;
                }
            }
            
            if(posTime >= opStartTime && posTime <= opEndTime)
            {
                posTime = opEndTime;
            }
        }
        
        answer = $"{posTime/60:00}:{posTime%60:00}";
        
        return answer;
    }
                                  
    private int StringToTime(string str)
    {
        string[] videoString = str.Split(':');
        
        int m = int.Parse(videoString[0]);
        int s = int.Parse(videoString[1]);
        
        return m*60 + s;
    }
}