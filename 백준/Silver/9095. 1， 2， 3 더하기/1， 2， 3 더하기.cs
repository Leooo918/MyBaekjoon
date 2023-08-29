using System;
using System.Text;
using System.Collections;

class Program
{
    static void Main()
    {
        int[] dp = new int[12];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        int t = int.Parse(Console.ReadLine()); //테스트케이스 수
        int[] testCase = new int[t];

        for (int k = 0; k < t; k++)
        {
            testCase[k] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < testCase.Length; i++)
        {
            for (int j = 4; j <= testCase[i]; j++)
            {
                if (dp[j] != 0)
                {
                    continue;
                }
                dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
            }
            Console.WriteLine(dp[testCase[i]]);
        }

    }
}