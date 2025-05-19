#include <iostream>
#include <algorithm>

using namespace std;

int t;
int n, w;
int arr[20001];
int dpA[10001], dpB[10001], dpC[10001];

void calc(int start)
{
	for (int i = start; i < n; i++)
	{
		dpA[i + 1] = min(dpB[i] + 1, dpC[i] + 1);

		if (arr[i] + arr[n + i] <= w)
		{
			dpA[i + 1] = min(dpA[i + 1], dpA[i] + 1);
		}
		if (i > 0 && arr[i - 1] + arr[i] <= w && arr[n + i - 1] + arr[n + i] <= w)
		{
			dpA[i + 1] = min(dpA[i + 1], dpA[i - 1] + 2);
		}

		if (i < n - 1)
		{
			dpB[i + 1] = dpA[i + 1] + 1;
			if (arr[i] + arr[i + 1] <= w)
			{
				dpB[i + 1] = min(dpB[i + 1], dpC[i] + 1);
			}

			dpC[i + 1] = dpA[i + 1] + 1;
			if (arr[n + i] + arr[n + i + 1] <= w)
			{
				dpC[i + 1] = min(dpC[i + 1], dpB[i] + 1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n >> w;

		for (int i = 0; i < n * 2; i++)
		{
			cin >> arr[i];
		}

		dpA[0] = 0;
		dpB[0] = 1;
		dpC[0] = 1;

		calc(0);
		int answer = min(30000, dpA[n]);


		if (n > 1)
		{
			if (arr[0] + arr[n - 1] <= w)
			{
				dpA[1] = 1;
				dpB[1] = 2;
				dpC[1] = ((arr[n] + arr[n + 1] <= w) ? 1 : 2);

				calc(1);
				answer = min(answer, dpC[n - 1] + 1);
			}

			if (arr[n] + arr[n + n - 1] <= w)
			{
				dpA[1] = 1;
				dpB[1] = ((arr[0] + arr[1] <= w) ? 1 : 2);
				dpC[1] = 2;

				calc(1);
				answer = min(answer, dpB[n - 1] + 1);
			}

			if (arr[n] + arr[n + n - 1] <= w && arr[0] + arr[n - 1] <= w)
			{
				dpA[1] = 0;
				dpB[1] = 1;
				dpC[1] = 1;

				calc(1);
				answer = min(answer, dpA[n - 1] + 2);
			}
		}

		cout << answer << '\n';
	}
}