using System;

class TestClass
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        int N = int.Parse(sr.ReadLine());
        string[] NArrayStr = sr.ReadLine().Split();
        int[] NArray = new int[N];
        for(int i = 0; i < NArrayStr.Length; i++)
        {
            NArray[i] = int.Parse(NArrayStr[i]);
        }

        int M = int.Parse(sr.ReadLine());
        string[] MArrayStr = sr.ReadLine().Split();
        int[] MArray = new int[M];
        for(int i = 0; i < MArray.Length; i++)
        {
            MArray[i] = int.Parse(MArrayStr[i]);
        }

        List<int> resultSequencce = new List<int>();
        int max = 0;
        int maxI = 0;
        int maxJ = 0;
        int NIndex = 0;
        int MIndex = 0;
        bool isEqual = false;

        while(NIndex < NArray.Length && MIndex < MArray.Length)
        {
            max = 0;
            isEqual = false;
            for (int i = NIndex; i < NArray.Length; i++)
            {
                for (int j = MIndex; j < MArray.Length; j++)
                {
                    if (NArray[i] == MArray[j])
                    {
                        isEqual = true;
                        if (max < NArray[i])
                        {
                            max = NArray[i];
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }

            if (!isEqual)
            {
                break;
            }

            resultSequencce.Add(max);
            NIndex = maxI + 1;
            MIndex = maxJ + 1;
        }

        Console.WriteLine(resultSequencce.Count);
        Console.WriteLine(string.Join(" ", resultSequencce));
    }
}
