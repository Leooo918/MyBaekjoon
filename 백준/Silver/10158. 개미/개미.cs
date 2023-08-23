using System;
using System.Text;
using System.Collections;

class Program
{
    static void Main()
    {
        bool isGoingUp = true;
        bool isGoingRight = true;

        int w = 0;
        int h = 0;
        int p = 0;
        int q = 0;
        int t = 0;

        string[] input = Console.ReadLine().Split();
        string[] inputs = Console.ReadLine().Split();
        t = int.Parse(Console.ReadLine());

        w = int.Parse(input[0]);
        h = int.Parse(input[1]);
        p = int.Parse(inputs[0]);
        q = int.Parse(inputs[1]);

        p += t;
        q += t;

        p %= (2 * w);
        q %= (2 * h);

        if(p > w)
        {
            p = 2 * w - p;
        }
        if(q > h)
        {
            q = 2 * h - q;
        }

        Console.WriteLine(p + " " + q);
    }
}