#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> v;
int arr[9];
int cnt = 0;

void dfs(int num, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = num; i < n; i++) {
			arr[k] = v[i];
			dfs(i, k + 1);
		}
	}
}


int main(int argc, char** argv)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (find(v.begin(), v.end(), a) == v.end()) {
			v.push_back(a);
		}
	}
	n = v.size();
	sort(v.begin(), v.end());

	dfs(0, 0);
}