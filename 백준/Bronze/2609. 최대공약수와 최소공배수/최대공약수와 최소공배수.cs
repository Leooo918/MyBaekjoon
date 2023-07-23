using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split();


        int A = int.Parse(inputs[0]);
        int B = int.Parse(inputs[1]);

        int gcd = GetGcd(A, B);
        int lcm = A * B / gcd;

        Console.WriteLine(gcd);
        Console.WriteLine(lcm);
    }

    static int GetGcd(int a, int b)
    {
        if (a % b == 0) return b;
        else
        {
            return GetGcd(b, a % b);
        }
    }
    
}