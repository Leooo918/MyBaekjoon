#include <iostream>
#include <vector>
#include<string.h>

using namespace std;

int n, m;
int a, b;
int arr[2001];
bool dp[2001][2001];

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i][i] = true;
	}

	for (int i = 1; i < n; i++)
	{
		dp[i][i + 1] = (arr[i] == arr[i + 1]);
	}

	for (int k = 2; k < n; k++)
	{
		for (int i = 0; i <= n - k; i++)
		{
			int j = i + k;

			bool isPelindrom = (arr[i] == arr[j] && dp[i + 1][j - 1]);
			dp[i][j] = isPelindrom;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}