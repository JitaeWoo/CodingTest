using System;

public class Solution {
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        
        if(a == b && a == c && a == d)
        {
            answer = 1111 * a;
        }
        else if((a == b && c == d)
               || (b == c && a == d)
               || (a == c && b == d))
        {
            int p = 0;
            int q = 0;
            
            if(a == b)
            {
                p = a;
                q = c;
            }
            else if(a == c)
            {
                p = a;
                q = d;
            }
            else if(a == d)
            {
                p = a;
                q = b;
            }
            
            answer = (p + q) * Math.Abs(p - q);
        }
        else if((a == b && a == c)
               || a == c && a == d
               || b == c && b == d
               || a == b && a == d)
        {
            int p = 0;
            int q = 0;
            
            if(a == b && a == c)
            {
                p = a;
                q = d;
            }
            else if(a == b && a == d)
            {
                p = a;
                q = c;
            }
            else if(a == c && a == d)
            {
                p = a;
                q = b;
            }
            else
            {
                p = b;
                q = a;
            }
            
            answer = (10 * p + q)*(10 * p + q);
        }
        else if(a == b || a == c || a == d
               || b == c || b == d
               || c == d)
        {
            answer = 1;
            if(a != b && a != c && a != d)
            {
                answer *= a;
            }
            if(b != a && b != c && b != d)
            {
                answer *= b;
            }
            if(c != b && c != a && c != d)
            {
                answer *= c;
            }
            if(d != b && d != c && d != a)
            {
                answer *= d;
            }
        }
        else
        {
            int min = int.MaxValue;
            
            int[] array = {a, b, c, d};
            
            foreach(int num in array)
            {
                if(min > num)
                {
                    min = num;
                }
            }
            
            answer = min;
        }
        
        return answer;
    }
}