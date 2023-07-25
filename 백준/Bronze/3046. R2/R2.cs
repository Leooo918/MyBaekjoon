using System;

class Program
{
    static void Main() {
        string[] s1=Console.ReadLine().Split(' ');
        int r=int.Parse(s1[0]);
        int s=int.Parse(s1[1]);
        Console.Write(2*s-r);
    }
}