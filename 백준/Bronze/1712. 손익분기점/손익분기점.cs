using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();

        ulong num = 1;

        ulong A = ulong.Parse(input[0]);
        ulong B = ulong.Parse(input[1]);
        ulong C = ulong.Parse(input[2]);

        //1대를 팔았을 때
        ulong totalProduceMoney = A + B;
        ulong totalSaledMoney = C;

        if (B >= C) Console.WriteLine(-1);
        else
        {
            for (; totalProduceMoney >= totalSaledMoney; num++)
            {
                totalSaledMoney += C;
                totalProduceMoney += B;
            }
            Console.WriteLine(num);
        }



    }

}

