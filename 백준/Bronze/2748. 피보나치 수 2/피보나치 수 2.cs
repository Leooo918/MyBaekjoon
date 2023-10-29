using System;

    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] pivo = new long[3] { 0, 1, 0 };

            for (int i = 1; i < n; i++)
            {
                pivo[2] = pivo[0] + pivo[1];
                pivo[0] = pivo[1];
                pivo[1] = pivo[2];
            }
            if (n == 0)
            {
                Console.WriteLine(pivo[0]);

            }
            else if (n == 1)
            {
                Console.WriteLine(pivo[1]);

            }
            else
            {
                Console.WriteLine(pivo[2]);
            }

        }
    
}