#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
#define INF 1e9


int t;
bool key[26];
int map[100][100];
bool visit[100][100];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool canEnter(int x, int y)
{
	if (map[x][y] == -2) return false;
	return true;
}

void tryPush(unordered_map<int, queue<pair<int, int>>>& m, queue<pair<int, int>>& q, int y, int x)
{
	if (map[y][x] >= 0 && map[y][x] < 26 && key[map[y][x]] == false)
	{
		m[map[y][x]].push({ y, x });
		return;
	}

	q.push({ y, x });
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		int h, w;
		int answer = 0;
		memset(visit, false, sizeof(visit));
		memset(key, false, sizeof(key));
		cin >> h >> w;

		// 서류 -3, 벽 -2 빈칸 -1
		for (int i = 0; i < h; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < w; j++)
			{
				if (s[j] == '$')
				{
					map[i][j] = -3;
				}
				else if (s[j] == '*')
				{
					map[i][j] = -2;
				}
				else if (s[j] == '.')
				{
					map[i][j] = -1;
				}
				else if (s[j] >= 'A' && s[j] <= 'Z')
				{
					map[i][j] = (s[j] - 'A');
				}
				else if (s[j] >= 'a' && s[j] <= 'z')
				{
					map[i][j] = (26 + (s[j] - 'a'));
				}
			}

		}

		string keyStr;
		cin >> keyStr;
		if (keyStr != "0")
		{
			for (int i = 0; i < keyStr.size(); i++)
			{
				int num = keyStr[i] - 'a';
				key[num] = true;
			}
		}
		
		queue<pair<int, int>> q;
		unordered_map<int, queue<pair<int, int>>> doormap;
		//가장자리 탐색하기 위해서
		for (int i = 0; i < h; i++)
		{
			if (canEnter(i, 0))
			{
				visit[i][0] = true;
				tryPush(doormap, q, i, 0);
			}
			if (canEnter(i, w - 1)) 
			{
				visit[i][w - 1] = true;
				tryPush(doormap, q, i, w - 1);
			}
		}
		for (int i = 1; i < w - 1; i++)
		{
			if (canEnter(0, i)) 
			{
				visit[0][i] = true;
				tryPush(doormap, q, 0, i);
			}
			if (canEnter(h - 1, i)) 
			{
				visit[h - 1][i] = true;
				tryPush(doormap, q, h - 1, i);
			}
		}

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			//열쇠 있는 곳에 도달하게 되면
			if (map[cy][cx] >= 26)
			{
				int keynum = (map[cy][cx] - 26);
				key[keynum] = true;

				auto iter = doormap.find(keynum);
				if (iter != doormap.end())
				{
					queue<pair<int, int>> doorq = iter->second;
					while (doorq.empty() == false)
					{
						q.push(doorq.front());
						doorq.pop();
					}
				}
			}
			if (map[cy][cx] == -3) answer++;

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (visit[ny][nx] == true) continue;
				if (canEnter(ny, nx) == false) continue;

				visit[ny][nx] = true;
				if (canEnter(ny, nx)) tryPush(doormap, q, ny, nx);
			}
		}

		cout << answer << '\n';
	}
}