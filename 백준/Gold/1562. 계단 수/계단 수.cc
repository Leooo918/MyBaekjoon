#include <iostream>
#include<cstring>
#include <vector>
#include <set>

using namespace std;
#define INF 1e9
#define MOD 1000000000

int n;
int visit = 0;
int dp[100][100][1024];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	if (n < 10)
	{
		cout << 0;
		return 0;
	}

	for (int i = 1; i < 10; i++)
	{
		dp[0][i][1 << i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 1024; k++)
			{
				int bit = k | (1 << j);
				if (j == 0)
				{
					dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j + 1][k]) % MOD;
				}
				else if (j == 9)
				{
					dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j - 1][k]) % MOD;
				}
				else
				{
					dp[i][j][bit] = (dp[i][j][bit] + dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k]) % MOD;
				}
			}
		}
	}

	long long int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + dp[n - 1][i][1023]) % MOD;
	}
	cout << sum;

}