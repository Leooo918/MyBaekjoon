#include <iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<map>


using namespace std;

int n, m, a, b;
map<int, vector<pair<int, int>>> arr;
int visit[1001];

void bfs()
{
	memset(visit, 0x3f3f3f3f, sizeof(visit));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ a,0 });

	while (!q.empty())
	{
		int cp = q.top().first;
		int cc = q.top().second;
		q.pop();

		if (visit[cp] < cc)continue;


		for (int i = 0; i < arr[cp].size(); i++)
		{
			int np = arr[cp][i].first;
			int nc = cc + arr[cp][i].second;

			if (visit[np] > nc)
			{
				q.push({ np,nc });
				visit[np] = nc;
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		arr[s].push_back({ e,c });
	}

	cin >> a >> b;

	bfs();
	
	cout << visit[b];
}