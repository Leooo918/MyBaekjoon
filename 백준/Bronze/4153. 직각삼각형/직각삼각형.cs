using System;
using System.Text;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        while (true)
        {
            string[] inputs = Console.ReadLine().Split();

            int A = int.Parse(inputs[0]);
            int B = int.Parse(inputs[1]);
            int C = int.Parse(inputs[2]);

            if (A + B + C == 0) break;

            if (A * A + B * B == C * C) Console.WriteLine("right");
            else if (A * A + C * C == B * B) Console.WriteLine("right");
            else if (B * B + C * C == A * A) Console.WriteLine("right");
            else Console.WriteLine("wrong");

        }
    }
}