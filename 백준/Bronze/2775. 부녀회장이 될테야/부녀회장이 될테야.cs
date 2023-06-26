using System;
class Program
{
    static void Main(string[] args)
    {
        int num = int.Parse(Console.ReadLine());


        while (num > 0)
        {
            int k = int.Parse(Console.ReadLine());
            int n = int.Parse(Console.ReadLine());

            int[,] dp = new int[k + 1, n];

            for (int i = 1; i < n + 1; i++)
            {
                dp[0, i - 1] = i;
            }

            for (int i = 1; i < k + 1; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int l = 0; l < j + 1; l++)
                    {
                        dp[i, j] += dp[i - 1, l];
                    }
                }
            }
            Console.WriteLine(dp[k, n - 1]);
            num--;
        }
    }
}
