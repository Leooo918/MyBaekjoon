using System;
using System.Text;
using System.Collections;

class Program
{
    static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        string[] b = Console.ReadLine().Split();

        int[] num = new int[a];
        int[] n = new int[a];

        int total = 0;

        for (int i = 0; i < a; i++)
        {
            num[i] = int.Parse(b[i]);

            for (int j = 0; j < i; j++)
            {
                if (num[i] < num[j])
                {
                    int temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }

        for(int i = 0; i < a; i++)
        {
            n[i] = num[i];
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < i; j++)
            {
                num[i] += n[j];
            }
        }

        for (int i = 0; i < a; i++)
        {
            total += num[i];
        }

        Console.WriteLine(total);
    }
}