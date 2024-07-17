using System;
using System.Collections;

namespace baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            Console.WriteLine(double.Parse(input[0]) / double.Parse(input[1]));
        }
    }
}