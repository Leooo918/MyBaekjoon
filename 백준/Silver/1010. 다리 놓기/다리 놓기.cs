using System;

class Beakjoon_1010
{
    // 최대 값이 –±5.0 × 10^−324 ~ ±1.7 × 10^308 인 long을 사용
    static long[,] result= new long[30, 30];

    static void Main()
    {
        // 실행 해야하는 갯수
        int i_count = int.Parse(Console.ReadLine());

        // nCr을 미리 계산
        Combination();

        while (i_count > 0)
        {
            //  테스트 케이스 정수 a, b
            string[] s_data = Console.ReadLine().Split();

            int i_n = int.Parse(s_data[0]);
            int i_r = int.Parse(s_data[1]);

            // 계산된 nCr 호출
            Console.WriteLine(result[i_r, i_n]);

            i_count--;
        }
    }

    // nCr 함수
    public static void Combination()
    {
        for (int i = 1; i < 30; i++)
        {
            result[i, i] = 1;
            result[i, 1] = i;
        }

        for (int i = 2; i < 30; i++)
            for (int j = 2; j < 30; j++)
                if (i > j)
                    result[i, j] = result[i - 1, j - 1] + result[i - 1, j];
    }
}