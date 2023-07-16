using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int[] input = new int[3];
        int[] outputs = new int[10];

        int num = 1;
        int numNum = 0;

        int[] numArr;

        for (int i = 0; i < 3; i++)
        {
            input[i] = int.Parse(Console.ReadLine());
            num *= input[i];
        }

        numNum = num.ToString().Length;
        numArr = new int[numNum];

        for (int i = 0; i < numNum; i++)
        {
            numArr[i] = int.Parse(num.ToString().ToCharArray()[i].ToString());
        }

        for (int i = 0; i < numNum; i++)
        {
            outputs[numArr[i]]++;
        }

        for(int i = 0; i < 10; i++)
        {
            Console.WriteLine(outputs[i]);
        }
    }
}
