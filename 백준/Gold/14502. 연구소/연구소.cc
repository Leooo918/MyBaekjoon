#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int arr[9][9];
int temp[9][9];
int visit[9][9];
int answer = 0;
vector<pair<int, int>> v;

int xx[4]{ 0,0,1,-1 };
int yy[4]{ 1,-1,0,0 };

void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2)q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cx + xx[i];
			int dy = cy + yy[i];

			if (visit[dx][dy] == 1 || temp[dx][dy] != 0 ||
				dx < 0 || dy < 0 || dx >= n || dy >= m) continue;

			visit[dx][dy] = 1;
			temp[dx][dy] = 2;
			q.push({ dx,dy });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}

	if (cnt > answer) answer = cnt;
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
			temp[i][j] = arr[i][j];
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)v.push_back({ i,j });
		}
	}

	reset();

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				temp[v[i].first][v[i].second] = 1;
				temp[v[j].first][v[j].second] = 1;
				temp[v[k].first][v[k].second] = 1;

				bfs();

				reset();
			}
		}
	}

	cout << answer;
}