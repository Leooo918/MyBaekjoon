#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

string a, b;
int dp[1001][1001] = { 0, };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

		}
	}

	cout << dp[a.size()][b.size()];
}