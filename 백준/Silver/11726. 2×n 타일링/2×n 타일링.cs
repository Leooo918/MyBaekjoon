using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        int[] dp = new int[1000];         //입력은 1<= n <=1000
        dp[0] = 1;
        dp[1] = 2;


        for (int i = 2; i < n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }

        Console.WriteLine(dp[n - 1]);
    }
}