using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            // 행렬 크기 입력받기
            string[] s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int m = int.Parse(s[1]);

            // n*m 크기의 행렬 A,B 만들기
            int[,] A = new int[n, m];
            int[,] B = new int[n, m];

            // 행렬 A에 값 삽입
            for (int i = 0; i < n; i++)
            {
                // 한 줄 입력 받고
                string[] line = Console.ReadLine().Split();
                for (int j = 0; j < m; j++)
                {
                    // 한 줄의 각 요소를 int형변환 후 행렬에 저장하기
                    A[i, j] = int.Parse(line[j]);
                }
                
            }

            // 행렬 B에 값 삽입
            for (int i = 0; i < n; i++)
            {
                // 한 줄 입력 받고
                string[] line = Console.ReadLine().Split();
                for (int j = 0; j < m; j++)
                {
                    // 한 줄의 각 요소를 행렬에 저장하기
                    B[i, j] = int.Parse(line[j]);
                }
            }

            // 행렬 덧셈 및 출력
            for (int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    Console.Write(A[i, j] + B[i, j] + " ");  
                }
                Console.WriteLine();  // 다음 줄로 
            }
        }
    }
}