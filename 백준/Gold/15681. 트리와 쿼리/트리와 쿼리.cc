#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N, R, Q;
int a, b;
vector<int> v[100001];
vector<int> tree[100001];
int dp[100001];
bool visit[100001];
int cnt = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int root)
{
	dp[root] = 1;

	if (tree[root].size() == 0)
	{
		return 1;
	}

	for (int i = 0; i < tree[root].size(); i++)
	{
		dp[root] += dfs(tree[root][i]);
	}

	return dp[root];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> Q;

	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(R);
	visit[R] = true;

	while (!q.empty())
	{
		int c = q.front();
		q.pop();

		for (int i : v[c])
		{
			if (visit[i]) continue;

			tree[c].push_back(i);
			q.push(i);

			visit[i] = true;
		}
	}

	dp[R] = dfs(R);

	for (int i = 0; i < Q; i++)
	{
		cin >> a;
		cout << dp[a] << '\n';
	}
}