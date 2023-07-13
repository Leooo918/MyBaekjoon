using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int inputNum = int.Parse(Console.ReadLine());

        int[] input = new int[inputNum];

        int temp;

        for (int i = 0; i < inputNum; i++)
        {
            input[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < inputNum; i++)
        {
            for (int j = i; j < inputNum; j++)
            {
                if (input[i] > input[j])
                {
                    temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                }
            }
        }

        for (int i = 0; i < inputNum; i++)
        {
            Console.WriteLine(input[i]);
        }

    }
}
