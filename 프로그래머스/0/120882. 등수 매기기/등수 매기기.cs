using System;
using System.Collections.Generic;

public struct Score : IComparable<Score>
{
    public int index;
    public float score;

    public Score(int index, float score)
    {
        this.index = index;
        this.score = score;
    }

    int IComparable<Score>.CompareTo(Score other)
    {
        float temp = other.score - score;
        if (temp > 0)
        {
            return 1;
        }
        else if(temp < 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

public class Solution {
    public int[] solution(int[,] score) {
        int[] answer = new int[score.GetLength(0)];
        List<Score> list = new List<Score>();

        for (int i = 0; i < score.GetLength(0); i++)
        {
            float average = (score[i, 0] + score[i, 1]) / 2f;
            list.Add(new Score(i, average));
        }

        list.Sort();

        float currentScore = -1;
        int currentRank = 0;
        int totalRank = 0;

        foreach(Score s in list)
        {
            totalRank++;
            if (currentScore != s.score)
            {
                currentScore = s.score;
                currentRank = totalRank;
            }

            answer[s.index] = currentRank;
        }
        
        return answer;
    }
}