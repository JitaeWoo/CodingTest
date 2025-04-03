using System;

public class Solution {
    public int solution(string[] spell, string[] dic) {
        int answer = 0;
        
        foreach (string str in dic)
        {
            if (str.Length != spell.Length)
            {
                continue;
            }

            int check = 0;

            foreach(string s in spell)
            {
                for(int i = 0; i < str.Length; i++)
                {
                    if (s[0] == str[i])
                    {
                        check++;
                        break;
                    }
                }
            }

            if(check == str.Length)
            {
                answer = 1;
                break;
            }
        }

        if (answer == 0)
        {
            answer = 2;
        }
        
        return answer;
    }
}