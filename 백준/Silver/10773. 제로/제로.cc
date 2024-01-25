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
	int total = 0;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}
	}

	while (s.size() > 0) {
		total += s.top();
		s.pop();
	}

	cout << total;
}
