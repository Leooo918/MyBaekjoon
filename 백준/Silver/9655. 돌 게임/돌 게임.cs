using System;
using System.Collections;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        if(n % 2 == 0)
        {
            Console.WriteLine("CY");
        }
        else
        {
            Console.WriteLine("SK");
        }
    }
}
