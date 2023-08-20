using System;
using System.Text;
using System.Collections;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();

        int[] num = new int[input[0].Length];
        int jinbup = int.Parse(input[1]);

        double shipjinsu = 0;


        for (int i = 0; i < input[0].Length; i++)
        {
            num[i] = (int)input[0].ToCharArray()[i];

            if(num[i] > 64)
            { 
                num[i] -= 55;
            }
            else
            {
                num[i] -= 48;
            }
        }

        for(int i = 0; i < num.Length; i++)
        {
            shipjinsu += num[i] * Math.Pow(jinbup, (double)num.Length - i - 1);

        }



        Console.WriteLine(shipjinsu);
    }
}