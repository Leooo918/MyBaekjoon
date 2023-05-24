using System;

class Beakjoon_1009
{
    static void Main()
    {
        // 실행 해야하는 갯수
        int i_count = int.Parse(Console.ReadLine());

        while (i_count > 0)
        {
            //  테스트 케이스 정수 a, b
            string[] s_data = Console.ReadLine().Split();

            int i_a = int.Parse(s_data[0]);
            int i_b = int.Parse(s_data[1]);

            int result = i_a;

            // B를 4로 나눈 나머지 값을 곱하여 값을 도출
            for (int i = 1; i < i_b % 4 + 4; i++)
                result = (result * i_a) % 10;

            // 0은 존재하지 않으므로, 10으로 수정
            if (result == 0)
                result = 10;

            Console.WriteLine(result);

            i_count--;
        }
    }
}