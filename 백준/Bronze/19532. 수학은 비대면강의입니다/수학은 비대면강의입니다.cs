using System;
using System.Collections;

class Program
{
    static void Main()
    {
        string[] inputs = Console.ReadLine().Split();

        int a = int.Parse(inputs[0]);
        int b = int.Parse(inputs[1]);
        int c = int.Parse(inputs[2]);
        int d = int.Parse(inputs[3]);
        int e = int.Parse(inputs[4]);
        int f = int.Parse(inputs[5]);

        for (int x = -999;x <= 999; x++)
        {
            for (int y = -999; y <= 999; y++)
            {
                if (a * x + b * y == c && d * x + e * y == f)
                {
                    Console.WriteLine($"{x} {y}");
                    break;
                }
            }

        }

    }
}