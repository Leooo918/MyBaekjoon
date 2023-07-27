using System;
using System.Collections;

class Program
{
    static void Main()
    {
        int num = 0;

        int input = -1;

        while (true)
        {
            num = 0;

            input = int.Parse(Console.ReadLine());

            if (input == 0) break;

            int n = input;
            int m = input * 2;

            bool check = true; 
            //if (n == 1) n++;
            for (int i = n + 1; i <= m; i++)
            {
                check = true;
                for (int j = 2; j * j <= i; j++)
                {
                    if (i != j && i % j == 0)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    num++;
                }
            }
            Console.WriteLine(num);
        }
    }
}