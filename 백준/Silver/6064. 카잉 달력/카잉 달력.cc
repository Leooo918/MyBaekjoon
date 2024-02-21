#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int m, n, x, y;

	cin >> T;

	for (int t = 0; t < T; t++) {
		int rx, ry;
		
		cin >> m >> n >> x >> y;
		
		if (x > y) {
			rx = x - y + 1;
			ry = 1;
		}
		else {
			ry = y - x + 1;
			rx = 1;
		}

		int cnt = 1;
		int nx = 1;
		int ny = 1;

		while (true) {
			if (nx == rx && ny == ry) {
				cnt = cnt + x - rx;
				nx = x;
				ny = y;
				break;
			}
			else if (m - nx < n - ny) {
				ny = ny + m - nx + 1;
				cnt = cnt + m - nx + 1;
				nx = 1;
			}
			else if (m - nx > n - ny) {
				nx = nx + n - ny + 1;
				cnt = cnt + n - ny + 1;
				ny = 1;
			}
			else {
				cnt = cnt + n - ny;
				nx = m;
				ny = n;
				break;
			}
		}

		if (nx == x && ny == y) {
			cout << cnt << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}