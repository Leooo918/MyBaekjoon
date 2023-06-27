using System;
class Program
{
    static void Main(string[] args)
    {
        int testCaseNum = int.Parse(Console.ReadLine());
        int num = 0;

        while (testCaseNum > 0)
        {
            string input = Console.ReadLine();

            char[] a = input.ToCharArray();

            char[] dp = new char[a.Length];

            bool isIt = true;
            int pivot = 1;

            dp[0] = a[0];

            for (int i = 1; i < a.Length; i++)
            {
                if (dp[pivot - 1] != a[i])
                {
                    dp[pivot++] = a[i];
                }
                for (int j = 0; j < pivot - 1; j++)
                {
                    if (dp[j] == a[i])
                    {
                        isIt = false;
                    }
                }
            }

            

            if (isIt)
            {
                num++;
            }

            testCaseNum--;
        }
        Console.WriteLine(num);
    }
}
