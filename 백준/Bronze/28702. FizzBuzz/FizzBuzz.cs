using System;

class TestClass
{
    static void Main(string[] args)
    {
        string[] strArray = new string[3];
        
        for(int i = 0; i < strArray.Length; i++)
        {
            strArray[i] = Console.ReadLine();
        }

        int resultNum = 0;

        for(int i = 0; i < strArray.Length; i++)
        {
            if (int.TryParse(strArray[i], out resultNum))
            {
                resultNum += 3 - i;
                break;
            }
        }

        if(resultNum % 3 == 0 && resultNum % 5 == 0)
        {
            Console.WriteLine("FizzBuzz");
        }
        else if(resultNum % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if(resultNum % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
        {
            Console.WriteLine(resultNum);
        }
    }
}
