using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int input = int.Parse(Console.ReadLine());

        int factorial = 1;

        for(int i = 1; i <= input; i++)
        {
            factorial *= i;
        }

        Console.WriteLine(factorial);
    }

}
