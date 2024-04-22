#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> vec[100001];
int answer[100001];
int cnt = 1;
bool visited[100001];


void dfs(int r)
{
	queue<int> q;
	q.push(r);
	answer[r] = cnt++;
	visited[r] = true;

	while (!q.empty())
	{
		int cn = q.front();
		q.pop();

		for (int i = 0; i < vec[cn].size(); i++)
		{
			int nr = vec[cn][i];

			if (visited[nr]) continue;

			q.push(nr);
			answer[nr] = cnt++;
			visited[nr] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, r;

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << answer[i] << '\n';
	}
}