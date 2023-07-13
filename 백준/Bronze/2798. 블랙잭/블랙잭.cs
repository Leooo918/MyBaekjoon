using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split();

            int cnt = int.Parse(str[0]);
            int num = int.Parse(str[1]);
            
            int max = int.MinValue;
            int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray(); // string으로 입력받고 int형태의 배열로 저장

            for (int i = 0; i<cnt; i++ )
            {
                for(int j = i+1; j<cnt; j++)
                {
                    for(int k = j+1; k<cnt; k++)
                    {
                        int sum = arr[i] + arr[j] + arr[k];

                        if (sum <= num && sum > max) max = sum;
                    }
                }
            }
            Console.WriteLine(max);
        }
    }
}
