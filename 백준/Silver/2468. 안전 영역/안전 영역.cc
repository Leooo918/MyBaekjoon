#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

int n, maxCnt = 1, maxHeight = 0;
int arr[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[101][101];

using namespace std;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			maxHeight = max(maxHeight, arr[i][j]);
		}
	}

	for (int i = 1; i <= maxHeight; i++)
	{
		memset(visit, false, sizeof(visit));
		int cnt = 0;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				queue<pair<int, int>> q;
				bool enabled = false;
				q.push({ j,k });

				while (!q.empty())
				{
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					if (cx < 0 || cy < 0 || cx >= n || cy >= n || arr[cx][cy] <= i || visit[cx][cy]) continue;
					visit[cx][cy] = true;
					enabled = true;

					for (int i = 0; i < 4; i++)
					{
						int nx = cx + dx[i];
						int ny = cy + dy[i];

						q.push({ nx,ny });
					}
				}

				if (enabled) cnt++;
			}
		}
		maxCnt = max(maxCnt, cnt);
	}

	cout << maxCnt;
}