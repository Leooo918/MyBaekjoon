#include <iostream>
#include <queue>
#include<string.h>
using namespace std;

int n, m;
int cnt = 0;
int arr[101][101];
int visit[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool nodeExposed(int x, int y)
{
	int exposed = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (arr[nx][ny] == 0)
		{
			bool isInside = true;
			memset(visit, 0, sizeof(visit));

			queue<pair<int, int>> q;
			q.push({ nx,ny });
			visit[nx][ny] = 1;

			while (!q.empty() && isInside)
			{
				int cx = q.front().first;
				int cy = q.front().second;
				q.pop();

				for (int j = 0; j < 4; j++)
				{
					int nnx = cx + dx[j];
					int nny = cy + dy[j];

					//끝까지 갔다 = 노출되있다
					if (nnx < 0 || nny < 0 || nnx >= n || nny >= m)
					{
						isInside = false;
						break;
					}

					if (arr[nnx][nny] == 1 || visit[nnx][nny] == 1) continue;

					q.push({ nnx,nny });
					visit[nnx][nny] = 1;
				}
			}

			if (!isInside) exposed++;
		}
	}

	return exposed >= 2;
}

int main()
{
	bool noCheese = true;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) noCheese = false;
		}
	}


	while (!noCheese)
	{
		noCheese = true;
		queue<pair<int, int>> toRemove;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0) continue;
				noCheese = false;

				//다음에 지워진거긴 함ㅇㅇ
				if (nodeExposed(i, j))
				{
					toRemove.push({ i,j });
				}
			}
		}

		while (!toRemove.empty())
		{
			int x = toRemove.front().first;
			int y = toRemove.front().second;
			toRemove.pop();

			arr[x][y] = 0;
		}

		if(!noCheese) cnt++;
	}

	cout << cnt;
}