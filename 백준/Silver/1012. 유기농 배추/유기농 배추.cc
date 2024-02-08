#include <iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int xx[4]{ 1,-1,0,0 };
int yy[4]{ 0,0,1,-1 };

int a[50][50] = { 0 };
int v[50][50] = { 0 };
int m, n, k;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + xx[i];
		int ny = y + yy[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

		if (a[nx][ny] == 1 && v[nx][ny] == 0) {
			v[nx][ny]++;
			dfs(nx, ny);
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int ans = 0;

		memset(a, 0, sizeof(a));
		memset(v, 0, sizeof(v));

		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[j][i] == 1 && v[j][i] == 0) {
					ans++;
					v[j][i]++;
					dfs(j, i);
				}
			}
		}

		cout << ans << "\n";
	}
}