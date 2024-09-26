#include <iostream>
#include <queue>
#include<string.h>

using namespace std;

int visit[300001];
vector<int> load[300001];
//pair<int, int> arr[1000001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k, x;
	int a, b;

	memset(visit, -1, sizeof(visit));

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		load[a].push_back(b);
		//arr[i] = { a,b };
	}

	queue<int> q;
	q.push(x);
	visit[x] = 0;

	while (!q.empty())
	{
		int cv = q.front();
		q.pop();

		for (int i = 0; i < load[cv].size(); i++)
		{
			if (visit[load[cv][i]] >= 0)continue;

			q.push(load[cv][i]);
			visit[load[cv][i]] = visit[cv] + 1;
		}
	}

	bool city = false;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == k)
		{
			cout << i << '\n';
			city = true;
		}
	}

	if (city == false) cout << -1;
}