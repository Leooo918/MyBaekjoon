using System;
using System.Collections.Generic;

    class Program
    {
        static int[] input;

        static int N;
        static int M;
        static int V;

        static public int[,] map = new int[1001, 1001];
        static public bool[] visited = new bool[1001];

        static public Queue<int> queue = new Queue<int>();
        static public Stack<int> stack = new Stack<int>();

        static void Reset()
        {
            for (int i = 1; i <= N; i++)
            {
                visited[i] = false;
            }
        }
        static void DFS(int V)
        {
            visited[V] = true;

            Console.Write(V + " ");
            for (int i = 1; i <= N; i++)
            {
                if (map[V, i] == 1 && visited[i] == false)
                {
                    DFS(i);
                }
            }           
        }
        static void BFS(int V)
        {
            queue.Enqueue(V);
            visited[V] = true;
                        
            int start = V;
            while (queue.Count != 0)
            {
                //큐에서 나오는 값을 시작변수로 계속 바꿔줘야함
                start = queue.Dequeue();
                Console.Write(start + " ");
                for (int i = 1; i <= N; i++)
                {
                    if(map[start, i] == 1 && visited[i] == false)
                    {
                        queue.Enqueue(i);
                        visited[i] = true;
                    }
                }
            }
        }
        static void Main(string[] args)
        {
            input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            N = input[0];
            M = input[1];
            V = input[2];

            for (int i = 0; i < M; i++)
            {
                int[] mArray = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                map[mArray[0], mArray[1]] = 1;
                map[mArray[1], mArray[0]] = 1;
            }

            Reset();
            DFS(V);
            Console.WriteLine();
            Reset();
            BFS(V);
        }
    }
