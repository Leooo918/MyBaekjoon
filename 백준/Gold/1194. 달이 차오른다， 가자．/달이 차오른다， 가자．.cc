#include <iostream>
#include <queue>
#include<string.h>

using namespace std;

int n, m;

char arrMap[51][51];
int visit[51][51][1 << 6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	queue<pair<pair<int, int>, int>> moveQueue;
	string input;
	int answer = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		for (int j = 0; j < m; j++)
		{
			arrMap[i][j] = input[j];
			if (arrMap[i][j] == '0') 
			{
				visit[i][j][0] = 1;
				moveQueue.push({ { i,j },0 });
			}
		}
	}

	while (!moveQueue.empty())
	{
		int cy = moveQueue.front().first.first;
		int cx = moveQueue.front().first.second;
		int key = moveQueue.front().second;

		int current = visit[cy][cx][key];
		moveQueue.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visit[ny][nx][key] > 0) continue;
			char slot = arrMap[ny][nx];
			if (slot == '#') continue;

			if (slot >= 'a' && slot <= 'f')
			{
				int nextKey = (key | (1 << (slot - 'a')));
				visit[ny][nx][nextKey] = current + 1;
				moveQueue.push({ {ny, nx}, nextKey });
			}

			if (slot >= 'A' && slot <= 'F')
			{
				if ((key | (1 << (slot - 'A'))) == key)
				{
					visit[ny][nx][key] = current + 1;
					moveQueue.push({ {ny, nx}, key });
				}
			}

			if (slot == '.' || slot == '0')
			{
				visit[ny][nx][key] = current + 1;
				moveQueue.push({ {ny, nx}, key });
			}

			if (slot == '1')
			{
				answer = current;
				cout << answer;
				return 0;
			}
		}
	}

	cout << answer;
}