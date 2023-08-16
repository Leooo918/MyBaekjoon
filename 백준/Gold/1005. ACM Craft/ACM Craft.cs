using System;
using System.Collections.Generic;

class test
{
    static LinkedList<int>[] graph;
    static int[] indegree;

    static void Main(string[] args)
    {
        int T = int.Parse(Console.ReadLine());
        for (int i=0; i<T; i++)
        {                   
            string[] words = Console.ReadLine().Split(' ');
            int N = int.Parse(words[0]);
            int K = int.Parse(words[1]);
            int[] w = new int[N];

            string[] weights = Console.ReadLine().Split(' ');
            for (int j=0; j<N; j++)
            {
                w[j] = int.Parse(weights[j]);
            }

            indegree = new int[N];
            graph = new LinkedList<int>[N];
            for (int g = 0; g < N; g++)
                graph[g] = new LinkedList<int>();

            for (int j=0; j<K; j++)
            {
                string[] buildings = Console.ReadLine().Split(' ');
                int from = int.Parse(buildings[0]) - 1;
                int to = int.Parse(buildings[1]) - 1;

                graph[from].AddLast(to);
                indegree[to]++;
            }

            int W = int.Parse(Console.ReadLine());
            int result = topologicalSort(N, w, W-1); // 위상정렬 
            Console.WriteLine(result);
        }                
    }

    static int topologicalSort(int n, int [] weight, int end)
    {
        Queue<int> searchQ = new Queue<int>();
        Queue<int> resultQ = new Queue<int>();
        int[] arr = new int[n];
        for (int i=0; i<n; i++)
        {
            if (indegree[i] == 0)
            {
                searchQ.Enqueue(i);
                arr[i] = weight[i];
            }
        }

        while (searchQ.Count > 0)
        {
            int zeroIndegreeNode = searchQ.Dequeue();
            resultQ.Enqueue(zeroIndegreeNode);

            foreach (int linkedNode in graph[zeroIndegreeNode])
            {
                arr[linkedNode] = Math.Max(arr[linkedNode], arr[zeroIndegreeNode] + weight[linkedNode]);
                indegree[linkedNode]--;
                if (indegree[linkedNode] == 0)
                searchQ.Enqueue(linkedNode);
            }
        }

        return arr[end];
    }
}
    
