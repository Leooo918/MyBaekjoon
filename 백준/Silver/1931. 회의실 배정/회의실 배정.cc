#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());

	int cur = v[0].first;
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i].second >= cur) {
			cnt++;
			cur = v[i].first;
		}
	}

	cout << cnt;
}