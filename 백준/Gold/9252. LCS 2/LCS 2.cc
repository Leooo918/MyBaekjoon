#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

string a, b;
int dp[1001][1001] = { 0, };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	cout << dp[a.size()][b.size()];

	int x = a.size(), y = b.size();
	stack<char> answer;

	while (x > 0 && y > 0)
	{
		if (a[x - 1] == b[y - 1])
		{
			answer.push(a[x - 1]);
			--x;
			--y;
		}
		else
		{
			if (dp[x][y] == dp[x - 1][y]) x--;
			else y--;
		}
	}

	if (answer.size() > 0) cout << '\n';

	while (!answer.empty())
	{
		cout << answer.top();
		answer.pop();
	}
}