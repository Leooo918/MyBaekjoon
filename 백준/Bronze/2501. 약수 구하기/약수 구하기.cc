#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, count = 0;
	vector<int> div;

	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		if (n % i == 0) {
			div.push_back(i);
			count++;
		}
	}
	if (count < k)
		cout << 0;
	else
		cout << div[k - 1];

	return 0;
}