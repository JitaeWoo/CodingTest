using System;

public class Solution {
    private class UnionFind
    {
        public int[] Parents;
        public int[] Cyecles;
        
        public UnionFind(int n)
        {
            Parents = new int[n];
            for(int i = 0; i < n; i++)
            {
                Parents[i] = i;
            }
            Cyecles = new int[n];
        }
        
        public int Find(int x)
        {
            if(Parents[x] == x)
            {
                return x;
            }
            
            return Parents[x] = Find(Parents[x]);
        }
        
        public void Union(int x, int y)
        {
            x = Find(x);
            y = Find(y);
            
            if(x == y)
            {
                Cyecles[x]++;
                return;
            }
            
            if(x > y)
            {
                Parents[x] = y;
                Cyecles[y] += Cyecles[x];
            }
            else
            {
                Parents[y] = x;
                Cyecles[x] += Cyecles[y];
            }
        }
    }
    
    public int[] solution(int[,] edges) {
        int[] answer = new int[4];
        
        int max = 0;
        foreach(int num in edges)
        {
            if(max < num)
            {
                max = num;
            }
        }
        
        int[] checkStartNodes = new int[max];
        int[] checkEndNodes = new int[max];
        for(int i = 0; i < edges.GetLength(0); i++)
        {
            checkStartNodes[edges[i, 0] - 1]++;
            checkEndNodes[edges[i, 1] - 1]++;
        }
        
        for(int i = 0; i < max; i++)
        {
            if(checkStartNodes[i] > 1 && checkEndNodes[i] == 0)
            {
                answer[0] = i + 1;
                break;
            }
        }
        
        UnionFind uf = new UnionFind(max);
        
        for(int i = 0; i < edges.GetLength(0); i++)
        {
            if(edges[i, 0] == answer[0]) continue;
            
            uf.Union(edges[i, 0] - 1, edges[i, 1] - 1);
        }
        
        for(int i = 0; i < max; i++)
        {
            if(uf.Find(i) != i) continue;
            if(checkStartNodes[i] == 0 && checkEndNodes[i] == 0) continue;
            
            switch(uf.Cyecles[i])
            {
                case 0:
                    answer[2]++;
                    break;
                case 1:
                    answer[1]++;
                    break;
                case 2:
                    answer[3]++;
                    break;
            }
        }
        
        answer[2]--;
        
        return answer;
    }
}