#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;
bool visit[100001];

void bfs(int a) {
	queue<pair<int, int>> q;
	q.push({ a,0 });

	while (q.empty() == false) {
		int position = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (position == k) {
			cout << cnt;
			return;
		}

		if (position + 1 < 100001 && visit[position + 1] == false) {
			visit[position + 1] = true;
			q.push({ position + 1, cnt + 1 });
		}


		if (position - 1 >= 0 && visit[position - 1] == false) {
			visit[position - 1] = true;
			q.push({ position - 1, cnt + 1 });
		}

		if (position * 2 < 100001 && visit[position * 2] == false) {
			visit[position * 2] = true;
			q.push({ position * 2, cnt + 1 });
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int cnt = 0;
	cin >> n >> k;
	visit[n] = true;
	bfs(n);
}