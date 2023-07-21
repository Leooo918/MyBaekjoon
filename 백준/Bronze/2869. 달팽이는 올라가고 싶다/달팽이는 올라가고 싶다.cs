using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        double num = 0;

        string[] inputs = Console.ReadLine().Split();

        long A = long.Parse(inputs[0]);
        long B = long.Parse(inputs[1]);
        long V = long.Parse(inputs[2]);

        double oneDay = A - B;
        double target = V - A;

        num = Math.Ceiling(target / oneDay + 1);


        Console.WriteLine(num);
    }
}