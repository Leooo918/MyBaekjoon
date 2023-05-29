using System;

namespace baekjoon
{
    class Program
    {
        static long[] num;
        
        static long func(int n)
        {
            num[0] = 1;
            num[1] = 1;
            num[2] = 1;
            num[3] = 2;
            num[4] = 2;

            if (n > 4)
            {
                for (int i = 5; i < n; i++)
                {
                    num[i] = num[i - 1] + num[i - 5];
                }
            }

            return num[n - 1];
        }


        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());

            num = new long[101];

            while (a > 0)
            {
                int input = int.Parse(Console.ReadLine());

                Console.WriteLine(func(input));

                a--;
            }
        }
    }
}