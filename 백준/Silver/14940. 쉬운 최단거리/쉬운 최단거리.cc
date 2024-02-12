#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int xx[4]{ 0,0,1,-1 };
int yy[4]{ 1,-1,0,0 };

int n, m;
int M[1001][1001];
int answer[1001][1001];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	answer[x][y] = 1;

	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = fx + xx[i];
			int dy = fy + yy[i];

			if (dx >= 0 && dx < n && dy >= 0 && y < m 
				&& answer[dx][dy] == 0 && M[dx][dy] != 0) {
				answer[dx][dy] = answer[fx][fy] + 1;
				q.push({ dx,dy });
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	pair<int, int> target;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 2) target = { i,j };
		}
	}

	bfs(target.first, target.second);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == 0) cout << 0 <<" ";
			else cout << answer[i][j] - 1 << " ";
		}
		cout << "\n";
	}
}