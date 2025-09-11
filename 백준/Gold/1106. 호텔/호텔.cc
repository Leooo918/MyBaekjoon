#include <iostream>
#include<cstring>
#include <vector>
#include <set>

using namespace std;
#define INF 1e9

int c, n;
int cost[20];
int customer[20];

//dp[i]: i명의 고객을 확보하는 최소 비용
int dp[1101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> c >> n;

	for (int i = 0; i < n; i++) cin >> cost[i] >> customer[i];
	for (int i = 0; i <= c + 100; i++) dp[i] = INF;

	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = customer[i]; j <= c + 100; j++)
		{
			if (dp[j - customer[i]] == INF)continue;
			dp[j] = min(dp[j], dp[j - customer[i]] + cost[i]);
		}
	}

	int mincost = INF;
	for (int i = c; i <= c + 100; i++)
	{
		mincost = min(mincost, dp[i]);
	}
	cout << mincost;
}