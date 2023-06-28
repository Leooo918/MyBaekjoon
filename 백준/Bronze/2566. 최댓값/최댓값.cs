using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int[,] procession = new int[9, 9];

        int maxNum = -1;
        int[] maxNumPos = new int[2];

        for (int i = 0; i < 9; i++)
        {
            string[] input = Console.ReadLine().Split();

            for(int j = 0; j < 9; j++)
            {
                procession[i, j] = int.Parse(input[j]);
            }
        }


        for(int i = 0;i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(maxNum < procession[i, j])
                {
                    maxNumPos[0] = j;
                    maxNumPos[1] = i;
                    maxNum = procession[i, j];
                }
            }
        }

        Console.WriteLine(maxNum);
        Console.Write(maxNumPos[1] + 1);
        Console.Write(" ");
        Console.Write(maxNumPos[0] + 1);
    }
}
