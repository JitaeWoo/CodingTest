using System;

class TestClass
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        string[] input2 = Console.ReadLine().Split();

        int[] sizes = new int[6];
        for(int i = 0; i < sizes.Length; i++)
        {
            sizes[i] = int.Parse(input2[i]);
        }

        string[] input3 = Console.ReadLine().Split();

        int T = int.Parse(input3[0]);
        int P = int.Parse(input3[1]);

        int numT = 0;

        for(int i = 0; i < sizes.Length; i++)
        {
            if (sizes[i] % T == 0)
            {
                numT += sizes[i] / T;
            }
            else
            {
                numT += (sizes[i] / T) + 1;
            }
        }

        Console.WriteLine(numT);
        Console.WriteLine($"{N / P} {N % P}");
    }
}
