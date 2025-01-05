#include <iostream>
#include <vector>
#include<string.h>

using namespace std;

int n;
int arr[1001][3];
int dp[1001][3];
vector<int> v;
int answer = INT16_MAX;

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	dp[1][0] = arr[1][0];
	dp[1][1] = INT16_MAX;
	dp[1][2] = INT16_MAX;

	for (int j = 2; j <= n; j++)
	{
		dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
		dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
		dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
	}
	answer = min(dp[n][1], dp[n][2]);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == i) dp[1][j] = arr[1][j];
			else dp[1][j] = INT16_MAX;
		}

		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		if (i == 0) answer = min(answer, min(dp[n][1], dp[n][2]));
		if (i == 1) answer = min(answer, min(dp[n][0], dp[n][2]));
		if (i == 2) answer = min(answer, min(dp[n][0], dp[n][1]));
	}

	cout << answer;
}