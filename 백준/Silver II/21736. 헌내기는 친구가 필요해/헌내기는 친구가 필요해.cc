#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int xx[4]{ 0,0,1,-1 };
int yy[4]{ 1,-1,0,0 };

int a[601][601];
int visit[601][601];
int n, m;
int total = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int cx = dx + xx[i];
			int cy = dy + yy[i];

			if (!(cx >= 0 && cy >= 0 && cx < n && cy < m)) continue;

			if (visit[cx][cy] != 0) continue;

			if (a[cx][cy] == 0) {
				visit[cx][cy] = 1;
				q.push({ cx,cy });
			}
			if (a[cx][cy] == 1) {
				visit[cx][cy] = 1;
				total++;
				q.push({ cx,cy });
			}

		}
	}

}

int main(int argc, char** argv)
{
	int x, y;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char s;
			cin >> s;

			if (s == 'I') {
				x = i;
				y = j;
				visit[i][j] = 1;
				a[i][j] = 1;
			}
			else if (s == 'P') a[i][j] = 1;
			else if (s == 'X') a[i][j] = -1;
		}
	}

	bfs(x, y);

	if (total == 0)
		cout << "TT";
	else
		cout << total;
}