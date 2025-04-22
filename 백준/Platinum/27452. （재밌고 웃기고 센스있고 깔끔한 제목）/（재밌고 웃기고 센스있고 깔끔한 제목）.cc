#include <iostream>
#include <queue>
#include <algorithm>
#include<string.h>
#include <math.h>

using namespace std;

int t;
long long n, k;
long long Length[88];

char f(long long N, long long K)
{
	if (N <= 2)
	{
		if (K == 1)
			return '(';
		else
			return ')';
	}

	if (K == 1)
		return '(';
	else if (K == Length[N] + 2)
		return ')';
	else if (K > Length[N - 2] + 1)
		return f(N - 1, K - Length[N - 2] - 1);
	else
		return f(N - 2, K - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	Length[1] = 2;
	Length[2] = 2;

	for (int i = 3; i < 88; i++)
	{
		Length[i] = 2 + Length[i - 2] + Length[i - 1];
	}

	while (t--)
	{
		cin >> n >> k;

		if (n > 87)
		{
			long long l = (n - 86) / 2;
			n = n % 2 ? 87 : 86;
			if (k <= l)
			{
				cout << "(\n";
				continue;
			}
			k -= l;
		}

		if (Length[n] < k)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << f(n, k) << '\n';
		}
	}
}