#include <iostream>
#include<cstring>
#include <vector>
#include <set>

using namespace std;
#define INF 1e9

int n;
int weight[17][17];
int dp[17][1 << 16];

int dfs(int start, int visit)
{
	//전부 방문
	if (visit == (1 << n) - 1)
	{
		if (weight[start][0] == 0) return INF;
		return weight[start][0];
	}

	//이미 방문
	if (dp[start][visit] != -1)
		return dp[start][visit];
	dp[start][visit] = INF;

	for (int i = 1; i < n; i++)
	{
		//길이 없음
		if (weight[start][i] == 0) continue;
		//이미 방문한 
		if (visit & (1 << i)) continue;

		dp[start][visit] = min(dp[start][visit], dfs(i, visit | (1 << i)) + weight[start][i]);
	}

	return dp[start][visit];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> weight[i][j];
		}
		for (int j = 0; j < (1 << n); j++)
		{
			dp[i][j] = -1;
		}
	}
	
	cout << dfs(0, 1) << '\n';
}