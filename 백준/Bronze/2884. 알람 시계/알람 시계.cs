using System;
using System.Collections;

namespace baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();

            int hour = int.Parse(input[0]);
            int min = int.Parse(input[1]);

            

            if (min - 45 < 0)
            {
                if (hour > 0)
                    hour--;
                else
                    hour = 23;
                min = 60 + (min - 45);
            }
            else
            {
                min = min - 45;
            }

            Console.WriteLine(hour + " " + min) ;
        }
    }
}