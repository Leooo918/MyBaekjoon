#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

int n, m, cnt = 0;
int arr[51][51];
bool visit[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

using namespace std;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] == true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || arr[nx][ny] == 0 || visit[nx][ny]) continue;

			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	while (true)
	{
		int cnt = 0;

		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == false)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
	}
}