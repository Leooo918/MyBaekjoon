using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int input = int.Parse(Console.ReadLine());

        int totalNum = 0;

        int[] inputs = new int[input];

        string stringInputs = Console.ReadLine();

        for (int i = 0; i < input; i++)
        {
            inputs[i] = int.Parse(stringInputs[i].ToString());

            totalNum += inputs[i];
        }

        Console.WriteLine(totalNum);
    }
}
