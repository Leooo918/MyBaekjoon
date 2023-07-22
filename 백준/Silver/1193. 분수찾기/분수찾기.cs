using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int input = int.Parse(Console.ReadLine());

        int curUp = 1, curDown = 1;
        int curMax = 1;
        int curRepeatNum = 1;


        for (; curRepeatNum < input;)
        {
            if (curMax % 2 == 0)
            {
                //줄어들게(왼쪽 아래)
                if (curDown == 1)
                {
                    curMax++;
                    curUp++;
                }
                else
                {
                    curUp++;
                    curDown--;
                }
            }
            else
            {
                //늘어나게(오른쪽 위)
                if (curUp == 1)
                {
                    curMax++;
                    curDown++;
                }
                else
                {
                    curUp--;
                    curDown++;
                }
            }

            curRepeatNum++;
        }

        Console.WriteLine(curUp + "/" + curDown);

    }
}