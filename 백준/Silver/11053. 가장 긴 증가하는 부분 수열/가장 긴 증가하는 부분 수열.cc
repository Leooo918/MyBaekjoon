#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> m;
	vector<int> dp;

	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;

		m.push_back(j);
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		dp.push_back(1);
		for (int j = i - 1; j >= 0; j--) {
			if (m[i] > m[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		total = max(dp[i], total);
	}

	cout << total;
}