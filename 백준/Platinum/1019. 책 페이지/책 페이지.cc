#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include<unordered_set>
#include <cmath> 

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n < 10)
	{
		cout << "0 ";
		for (int i = 1; i < 10; i++)
		{
			cout << ((i <= n) ? 1 : 0) << ' ';
		}
		return 0;
	}

	int answer[10] = { 0,0,0,0,0,0,0,0,0,0 };

	for (int i = 1; i <= n; i *= 10)
	{
		int current_digit = (n / i) % 10;
		int higher_part = n / (i * 10);
		int lower_part = n % i;

		for (int j = 1; j < 10; ++j)
		{
			answer[j] += higher_part * i;

			if (current_digit > j)
			{
				answer[j] += i;
			}
			else if (current_digit == j)
			{
				answer[j] += lower_part + 1;
			}
		}

		//0은 따로 처리
		if (higher_part > 0) 
		{
			answer[0] += (higher_part - 1) * i;

			if (current_digit == 0) 
			{
				answer[0] += lower_part + 1;
			}
			else 
			{
				answer[0] += i;
			}
		}

		if (i > n / 10)  break;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << answer[i] << ' ';
	}
}