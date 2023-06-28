using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[,] procession = new string[5,100];

        int Length = 0;

        int maxLength = 0;

        for (int i = 0; i < 5; i++)
        {
            string input = Console.ReadLine();

            char[] a = input.ToCharArray();

            Length = input.Length;

            if(maxLength < Length)
            {
                maxLength = Length;
            }

            for (int j = 0; j < Length; j++)
            {
                string b = a[j].ToString();
                procession[i, j] = b;   
            }
        }


        for (int i = 0; i < maxLength; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                Console.Write(procession[j, i]);
            }
        }

    }
}
