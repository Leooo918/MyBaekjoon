using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int num = int.Parse(Console.ReadLine());

        int sosuCnt = 0;
        
        int[] input = new int[num];

        string[] Input = Console.ReadLine().Split();

        for(int i = 0; i < num; i++)
        {
            input[i] = int.Parse(Input[i]);

            if (CheckSosu(input[i]))
            {
                sosuCnt++;
            }
        }

        Console.WriteLine(sosuCnt);


    }

    static bool CheckSosu(int checkNum)
    {
        if(checkNum == 1)
        {
            return false;
        }

        for(int i = 2; i <= checkNum; i++)
        {
            for(int j = 2; j <= i; j++)
            {
                if (i * j == checkNum)
                {
                    return false;
                }
            }
        }

        return true;
    }

}
