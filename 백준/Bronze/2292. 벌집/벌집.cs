using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int num = int.Parse(Console.ReadLine());

        int i = 1;

        for(int j = 1; j < num; j += 6 * i++)
        {
        }

        Console.WriteLine(i);
    }

}

