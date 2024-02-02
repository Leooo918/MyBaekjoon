#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[i] = v[i - 1] + a;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << v[b] - v[a - 1] << "\n";
	}
}
