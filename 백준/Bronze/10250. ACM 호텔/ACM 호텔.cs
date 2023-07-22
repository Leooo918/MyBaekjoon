using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int testCaseNum = int.Parse(Console.ReadLine());

        for (int i = 0; i < testCaseNum; i++)
        {
            string[] input = Console.ReadLine().Split();

            int H = int.Parse(input[0]);
            int W = int.Parse(input[1]);
            int N = int.Parse(input[2]);

            int hotelNum = 000;

            int[,] hotel = new int[W, H];

            bool isEnd = false;

            for (int j = 0; j < W; j++)
            {
                for (int k = 0; k < H; k++)
                {
                    int curNum = H * j + k + 1;

                    if (curNum == N)
                    {
                        hotelNum = (k + 1) * 100 + j + 1;
                        Console.WriteLine(hotelNum);
                        break;
                    }
                }
            }

        }
    }
}