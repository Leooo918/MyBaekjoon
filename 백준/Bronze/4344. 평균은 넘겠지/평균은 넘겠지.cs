using System;

namespace baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            int tNum = int.Parse(Console.ReadLine());
            float[] grade = new float[1001];
            float everage;
            float overEverageStudentNum;

            while (tNum > 0)
            {
                everage = 0;
                overEverageStudentNum = 0;

                string[] input = Console.ReadLine().Split();

                int sNum = int.Parse(input[0]);
                for (int i = 1; i <= sNum; i++)
                {
                    grade[i] = float.Parse(input[i]);
                }

                for (int i = 1; i <= sNum; i++)
                {
                    everage += float.Parse(input[i]);
                }
                everage /= sNum;

                for (int i = 1; i <= sNum; i++)
                {
                    if (everage < grade[i])
                    {
                        overEverageStudentNum++;
                    }
                }
                Console.WriteLine("{0:0.##0}%",Math.Round(overEverageStudentNum / sNum * 100, 3));

                tNum--;
            }
        }
    }
}