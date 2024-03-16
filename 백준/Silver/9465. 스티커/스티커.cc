#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<tuple>

using namespace std;

int t;
int n;
int arr[100001][2];
int dp[100001][2];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i][0];
		for (int i = 0; i < n; i++)
			cin >> arr[i][1];

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[1][0] + dp[0][1];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < n; i++) {
			dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 2][1]);
			dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 2][0]);
		}

		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}

}