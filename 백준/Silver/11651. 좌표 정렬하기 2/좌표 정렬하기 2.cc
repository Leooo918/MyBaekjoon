#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<cmath>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	else return p1.second < p2.second;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p.begin(), p.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second << "\n";
	}
}
