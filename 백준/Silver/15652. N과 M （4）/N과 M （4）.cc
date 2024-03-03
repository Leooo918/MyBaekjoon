#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int num, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = num; i <= n; i++) {
			arr[k] = i;
			dfs(i, k + 1);
		}
	}
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	dfs(1, 0);
}
