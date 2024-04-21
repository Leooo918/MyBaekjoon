#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, R;
int arr[100];
vector<pair<int, int>> road[100];
int visit[100];
int answer = 0;

int dfs(int p)
{
	memset(visit, 0x3f3f3f3f, sizeof(visit));
	visit[p] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0,p });

	while (!pq.empty())
	{
		int cp = pq.top().first;
		int cr = pq.top().second;
		pq.pop();

		for (int i = 0; i < road[cr].size(); i++)
		{
			int np = road[cr][i].first;
			int nr = road[cr][i].second;

			if (cp + nr < visit[np])
			{
				visit[np] = cp + nr;
				pq.push({ cp + nr ,np });
			}
		}
	}
	
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (visit[i] <= M)
			cnt += arr[i];
	}

	return cnt;
}

int main()
{
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < R; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}


	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, dfs(i));
	}

	cout << answer;
}