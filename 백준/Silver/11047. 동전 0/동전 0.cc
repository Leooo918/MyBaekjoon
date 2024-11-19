#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, k;
	int cnt = 0;

	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	while (k > 0) {
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] <= k) {
				k -= v[i];
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}
