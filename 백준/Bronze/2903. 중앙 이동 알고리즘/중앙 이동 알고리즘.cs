using System;
using System.Collections;

class Program
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());

        int dotNum = 9;

        for (int i = 1; i < N; i++)
        {
            int l = (int)Math.Sqrt(dotNum);
            int num = (l * 2 - 1) * (l - 1);
            dotNum += num * 2 - (int)Math.Pow(l - 1, 2);
        }


        Console.WriteLine(dotNum);
    }
}