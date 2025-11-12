using System;

public class Solution {
    public int solution(string[] storage, string[] requests) {
        int answer = 0;
        char[,] array = new char[storage.Length, storage[0].Length];
        
        for(int i = 0; i < array.GetLength(0); i++)
        {
            for(int j = 0; j < array.GetLength(1); j++)
            {
                array[i, j] = storage[i][j];
            }
        }
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        foreach(string request in requests)
        {
            for(int i = 0; i < array.GetLength(0); i++)
            {
                for(int j = 0; j < array.GetLength(1); j++)
                {
                    if(array[i, j] != request[0]) continue;
                    
                    if(request.Length == 2)
                    {
                        array[i, j] = '2';
                        answer++;
                        continue;
                    }
                    
                    for(int k = 0; k < 4; k++)
                    {
                        if(CanGetOut(array, j+dx[k], i+dy[k]))
                        {
                            array[i, j] = '2';
                            answer++;
                            break;
                        }
                    }
                    
                    ClearArray(array, '1');
                }
            }
            
            ClearArray(array, '2');
        }
        
        return array.Length - answer;
    }
    
    private bool CanGetOut(char[,] array, int x, int y)
    {
        if(x < 0 || x >= array.GetLength(1)
           || y < 0 || y >= array.GetLength(0))
        {
            return true;
        }
        
        if(array[y, x] != '0') return false;
        
        array[y, x] = '1';
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++)
        {
            if(CanGetOut(array, x+dx[i], y+dy[i]))
            {
                return true;
            }
        }
        
        return false;
    }
    
    private void ClearArray(char[,] array, char target)
    {
        for(int i = 0; i < array.GetLength(0); i++)
        {
            for(int j = 0; j < array.GetLength(1); j++)
            {
                if(array[i, j] == target)
                {
                    array[i, j] = '0';
                }
            }
        }
    }
}