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
            int time = int.Parse(Console.ReadLine());

            min += time;

            while (min >= 60)
            {
                if (min >= 60)
                {
                    hour++;
                    min = -(60 - (min));
                }
            }


            if (hour > 23)
            {
                hour -= 24;
            }

            Console.WriteLine(hour + " " + min);
        }
    }
}