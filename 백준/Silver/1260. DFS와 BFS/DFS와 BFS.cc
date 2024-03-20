#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N, M, V;
int edges[1001][1001];
int visit[10001];

void dfs(int c) {
	visit[c] = 1;
	cout << c << " ";

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) continue;
		if (edges[c][i] == 1) dfs(i);
	}
}

void bfs() {
	queue<int> q;
	q.push(V);
	visit[V] = 1;

	while (!q.empty()) {
		int c = q.front();
		cout << c << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 1) continue;

			if (edges[c][i] == 1) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	cout << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	dfs(V);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs();
}