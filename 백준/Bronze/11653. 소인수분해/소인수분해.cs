using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int input = int.Parse(Console.ReadLine());

        List<int> nums = new List<int>();


        if (input != 1)
        {
            while (input != 1)
            {
                for (int i = 2; i <= input; i++)
                {
                    if (input % i == 0)
                    {
                        nums.Add(i);
                        input /= i;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i < nums.Count; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] < nums[j])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

        for (int i = 0; i < nums.Count; i++)
        {
            Console.WriteLine(nums[i]);
        }
    }
}