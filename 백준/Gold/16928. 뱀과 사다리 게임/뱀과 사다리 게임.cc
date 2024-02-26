#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<queue>


using namespace std;

int answer = INT16_MAX;
int l, s;

int arr[101];
int visit[101];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		int p = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i < 7; i++) {
			int np = p + i;

			if (np == 100) {
				answer = ++cnt;
				return;
			}

			if (visit[np] == 1)continue;

			if (arr[np] != 0)
				q.push({ arr[np], cnt + 1 });
			else 
				q.push({ np, cnt + 1 });

			visit[np] = 1;
		}

	}
}

int main(int argc, char** argv)
{
	cin >> l >> s;

	for (int i = 0; i < l + s; i++) {
		int n, m;
		cin >> n >> m;

		arr[n] = m;
	}

	bfs();

	cout << answer;
}