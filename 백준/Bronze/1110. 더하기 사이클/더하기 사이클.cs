using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int input = int.Parse(Console.ReadLine());

        int cnt = 0;
        int targetNum = 0;

        if (input < 10)
        {
            input *= 10;
        }

        targetNum = input;

        input = Cal(input);

        cnt++;


        for (; input != targetNum; cnt++)
        {
            input = Cal(input);
        }

        Console.WriteLine(cnt);
    }

    static int Cal(int c)
    {
        int q = c / 10;
        int w = c - q * 10;

        int e = q + w;

        c = w * 10 + FindLastNum(e);

        return c;
    }

    static int FindLastNum(int a)
    {
        if (a >= 10)
        {
            int b = a / 10;
            a = a - b * 10;
        }
        return a;
    }
}
