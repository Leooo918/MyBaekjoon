#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> vec[100001];
int answer[100001];
int cnt = 1;
bool visited[100001];


void dfs(int r)
{
	visited[r] = true;
	answer[r] = cnt++;

	for (int i = 0; i < vec[r].size(); i++)
	{
		if (visited[vec[r][i]] == true) continue;

		dfs(vec[r][i]);
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