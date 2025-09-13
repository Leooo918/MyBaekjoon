#include <iostream>
#include <vector>

using namespace std;
#define INF 1e9

int n;
vector<int> tree[1000001];
int dp[1000001][2];
bool visited[1000001];

void dfs(int index)
{
	if (visited[index]) return;

	visited[index] = true;
	dp[index][0] = 0;
	dp[index][1] = 1;

	for (int next : tree[index])
	{
		if (visited[next]) continue;
		dfs(next);
		dp[index][0] += dp[next][1];
		dp[index][1] += min(dp[next][0], dp[next][1]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	cout << min(dp[1][0], dp[1][1]) << '\n';
}
