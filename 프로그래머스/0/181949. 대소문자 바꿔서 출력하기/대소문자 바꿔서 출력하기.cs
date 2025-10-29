using System;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();

        int diff = 'a' - 'A';
        
        char[] array = s.ToCharArray();
        
        for(int i = 0; i < array.Length; i++)
        {
            if(array[i] < 'a')
            {
                array[i] = (char)(array[i] + diff);
            }
            else
            {
                array[i] = (char)(array[i] - diff);
            }
        }
        
        Console.Write(new string(array));
    }
}