using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        List<int> nums = new List<int>();

        int n = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());

        int total = 0;

        bool check = true;

        if (n == 1) n++;

        for (int i = n; i <= m; i++)
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
                nums.Add(i);
            }
        }

        if(nums.Count == 0)
        {
            Console.WriteLine(-1);
        }
        else
        {
            for (int i = 0; i < nums.Count; i++)
            {
                total += nums[i];
            }

            Console.WriteLine(total);
            Console.WriteLine(nums[0]);
        }
    }
}