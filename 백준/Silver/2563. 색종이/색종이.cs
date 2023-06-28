using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int[,] procession = new int[100,100];

        int num = int.Parse(Console.ReadLine());

        int totalNum = 0;

        for(int i = 0; i < num; i++)
        {
            int[] a = new int[2];

            string[] b = Console.ReadLine().Split();

            a[0] = int.Parse(b[0]);
            a[1] = int.Parse(b[1]);

            for(int j = 0; j < 100; j++)
            {
                for(int k = 0; k < 100; k++)
                {
                    if(j >= a[0] && j < a[0] + 10 && k >= a[1] && k < a[1] + 10)
                    {
                        procession[j, k] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                if(procession[i,j] == 1)
                {
                    totalNum++;
                }
            }
        }

        Console.WriteLine(totalNum);
    }
}
