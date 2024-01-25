#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(10001); { 0; }

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[a]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < v[i]; j++) {
			cout << i << "\n";
		}
	}
}
