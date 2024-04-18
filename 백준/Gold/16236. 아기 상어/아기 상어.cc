#include<iostream>
#include<string.h>
#include<queue>
#include<tuple>


using namespace std;

int n;
int arr[22][22];
int visit[22][22];
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

int bx, by;
int result = 0;
int c = 0;
int sz = 2;

bool eat = false;

void bfs(int a, int b, int sharkSize)
{
	queue<tuple<int, int, int>> q;
	q.push({ a, b, 0 });

	visit[b][a] = true;

	int temp;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());

		if (arr[y][x] > 0 && arr[y][x] < sharkSize && temp == cnt)
		{
			if ((by > y) || (by == y && bx > x))
			{
				by = y;
				bx = x;
				continue;
			}
		}

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx])
			{
				if (arr[ny][nx] <= sharkSize)
				{
					if (arr[ny][nx] > 0 && arr[ny][nx] < sharkSize && !eat)
					{
						eat = true;
						bx = nx;
						by = ny;
						temp = cnt + 1;
						result += temp;
					}
					else
					{
						q.push({ nx, ny, cnt + 1 });
						visit[ny][nx] = true;
					}
				}
			}
		}
	}
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				by = i;
				bx = j;
				arr[i][j] = 0;
			}
		}
	}

	while (true)
	{
		memset(visit, 0, sizeof(visit));
		bfs(bx, by, sz);

		if (eat)
		{
			eat = false;
			c += 1;
			arr[by][bx] = 0;

			if (c == sz)
			{
				sz += 1;
				c = 0;
			}
		}
		else
			break;
	}
	cout << result << '\n';
}