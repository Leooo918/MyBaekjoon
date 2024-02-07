#include <iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> dp{ 0, 0, 1, 1 };
	vector<int> v{ 0,1,1,1 };

	for (int i = 4; i <= n; i++) {
		int m = dp[i - 1];
		int l = i - 1;

		if (i % 3 == 0) {
			m = min(m, dp[i / 3]);
			l = dp[l] < dp[i / 3] ? l : i / 3;
		}
		if (i % 2 == 0) {
			m = min(m, dp[i / 2]);
			l = dp[l] < dp[i / 2] ? l : i / 2;
		}

		m += 1;
		dp.push_back(m);
		v.push_back(l);
	}


	cout << dp[n] << "\n";
	cout << n << " ";

	while (n != 1) {
		cout << v[n] << " ";
		n = v[n];
	}
}