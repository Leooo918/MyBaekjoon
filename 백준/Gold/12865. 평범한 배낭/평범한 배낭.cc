#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<tuple>

using namespace std;

int n, k;
vector<pair<int, int>> b;
int dp[101][100005] = { 0, };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		b.push_back({ w,v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int cw = b[i-1].first;
			int cv = b[i-1].second;

			if (cw > j)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			if((cv + dp[i-1][j-cw]) > dp[i-1][j]) 
				dp[i][j] = cv + dp[i - 1][j - cw];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
}