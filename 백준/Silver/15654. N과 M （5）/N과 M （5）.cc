#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
vector<int> v;

void dfs(int num, int k) {
	if (k == m) {
		bool b = true;
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				if (arr[i] == arr[j]) b = false;
			}
		}

		if (b == true) {
			for (int i = 0; i < m; i++)
				cout << arr[i] << " ";

			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			arr[k] = v[i];
			dfs(i + 1, k + 1);
		}
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	dfs(1, 0);
}
