using System;

public class Solution {
    private struct Robot
    {
        public int RouteIndex;
        public int[] CurPoint;
        
        public Robot(int x, int y)
        {
            RouteIndex = 0;
            CurPoint = new int[] {y, x};
        }
    }
    
    
    public int solution(int[,] points, int[,] routes) {
        int answer = 0;
        int[,] map = new int[101, 101];
        
        int robotCount = routes.GetLength(0);
        Robot[] robots = new Robot[robotCount];
        
        for(int i = 0; i < robotCount; i++)
        {
            robots[i] = new Robot(points[routes[i, 0] - 1, 1], points[routes[i, 0] - 1, 0]);
        }
        
        while(robotCount != 0)
        {
            for(int i = 0; i < robots.Length; i++)
            {
                if(robots[i].RouteIndex == routes.GetLength(1)) continue;
                
                if(++map[robots[i].CurPoint[0], robots[i].CurPoint[1]] == 2)
                {
                    answer++;
                }
                
                if(robots[i].CurPoint[0] == points[routes[i, robots[i].RouteIndex] - 1, 0]
                   && robots[i].CurPoint[1] == points[routes[i, robots[i].RouteIndex] - 1, 1])
                {
                    robots[i].RouteIndex++;
                    if(robots[i].RouteIndex >= routes.GetLength(1))
                    {
                        robotCount--;
                        continue;
                    }
                }
                
                int y = points[routes[i, robots[i].RouteIndex] - 1, 0];
                int x = points[routes[i, robots[i].RouteIndex] - 1, 1];
                
                if(robots[i].CurPoint[0] != y)
                {
                    robots[i].CurPoint[0] += y > robots[i].CurPoint[0] ? 1 : -1;
                }
                else
                {
                    robots[i].CurPoint[1] += x > robots[i].CurPoint[1] ? 1 : -1;
                }
            }
            
            Array.Clear(map, 0, map.Length);
        }
        
        
        return answer;
    }
}