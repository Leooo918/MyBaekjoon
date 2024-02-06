#include<string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<iterator>
#include<cmath>

using namespace std;



int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> vv(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> vv[i];
	}

	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end(), greater<int>());

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += v[i] * vv[i];
	}
	cout << total;
}