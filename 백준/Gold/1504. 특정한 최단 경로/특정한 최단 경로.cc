#include <iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int n, e;
int cf = 0;
int mv[4];
int answer = 0x3f3f3f3f;
vector<pair<int, int>> arr[801];

struct compare {
	bool operator()(const pair<int, int> a, const pair<int, int> b) {
		return (cf - a.first) > (cf - b.first);
	}
};

int d[801];
int visit[801];


int f(int a)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push({ a, d[a] });

	while (!pq.empty())
	{
		int cp = pq.top().first;
		int cc = pq.top().second;
		pq.pop();

		if (d[cp] != cc) continue;

		for (int i = 0; i < arr[cp].size(); i++)
		{
			int np = arr[cp][i].first;
			int nc = arr[cp][i].second;

			if (d[cp] + nc < d[np]) {
				d[np] = nc + d[cp];
				pq.push({ np, nc + d[cp] });
			}
		}
	}

	return d[cf];
}

void ff()
{
	int a = 0;
	int la = 0;
	for (int i = 0; i < 3; i++)
	{
		memset(d, 0x3f3f3f3f, sizeof(d));
		d[mv[i]] = 0;
		cf = mv[i + 1];

		la = f(mv[i]);
		a += la;
		if (la > 3000000)
		{
			answer = -1;
			return;
		}
	}
	answer = min(a, answer);
}


int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}

	mv[0] = 1;
	mv[3] = n;
	cin >> mv[1] >> mv[2];

	ff();

	int temp = mv[1];
	mv[1] = mv[2];
	mv[2] = temp;

	ff();

	cout << answer;
}