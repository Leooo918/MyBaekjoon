#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, k;
int visit[100001];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visit[n] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) {
			cout << cnt;
			return;
		}

		if (cur * 2 < 100001 && visit[cur * 2] == 0) {
			q.push({ (cur * 2), cnt });
			visit[cur * 2] = 1;
		}
		if (cur - 1 >= 0 && visit[cur - 1] == 0) {
			q.push({ (cur - 1), (cnt + 1) });
			visit[cur - 1] = 1;
		}
		if (cur + 1 < 100001 && visit[cur + 1] == 0) {
			q.push({ (cur + 1), (cnt + 1) });
			visit[cur + 1] = 1;
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	bfs();
}