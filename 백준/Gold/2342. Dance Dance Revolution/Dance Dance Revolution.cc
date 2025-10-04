#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
#define INF 1e9

int length = 1;
int arr[100001];
int dp[100001][5][5];
int value[5][5] = { {1, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4}, {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1} };

int f(int cur, int l, int r)
{
	if (cur == length - 1) return 0;
	if ((l != 0 && r != 0) && l == r) return INF;

	if (dp[cur][l][r] != -1) return dp[cur][l][r];
	
	dp[cur][l][r] = min(f(cur + 1, arr[cur + 1], r) + value[l][arr[cur + 1]], 
		f(cur + 1, l, arr[cur + 1]) + value[r][arr[cur + 1]]);
	return dp[cur][l][r];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr[length++];
	while (arr[length - 1] != 0)
		cin >> arr[length++];

	memset(dp, -1, sizeof(dp));

	cout << f(0, 0, 0);
}