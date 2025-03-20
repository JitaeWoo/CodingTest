using System;

class TestClass
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int N = int.Parse(sr.ReadLine());
        string[] fruitsStr = sr.ReadLine().Split();

        int[] fruits = new int[fruitsStr.Length];
        for (int i = 0; i < fruitsStr.Length; i++)
        {
            fruits[i] = int.Parse(fruitsStr[i]);
        }

        // 탕후루에 꽂힌 과일 개수 판별 용도
        int[] checkList = new int[10];
        int check = 0;

        int right = 0;
        int left = 0;

        int max = 0;

        while(right < fruits.Length)
        {
            if (check < 3)
            {
                checkList[fruits[right]]++;
            }

            check = 0;
            for(int i = 1; i < 10; i++)
            {
                if (checkList[i] != 0)
                {
                    check++;
                }
            }

            if(check < 3)
            {
                int temp = right - left + 1;
                if(temp > max)
                {
                    max = temp;
                }
                right++;
            }
            else
            {
                checkList[fruits[left]]--;
                left++;
            }
        }

        Console.WriteLine(max);
    }
}
