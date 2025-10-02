#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

int n, m;
bool iswall[11][11];
bool visit[11][11][11][11];

enum ballstate {
	none,
	fail,
	complete
};

struct ballpos
{
	pair<int, int> rpos;
	pair<int, int> bpos;
};
pair<int, int> goalPos;
ballpos initBallPos;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

ballpos moveball(ballpos ball, int direction)
{
	bool rstop = false;
	bool bstop = false;
	bool rcomplete = false;


	while (rstop == false || bstop == false)
	{
		pair<int, int> nextrpos = make_pair(ball.rpos.first + dx[direction], ball.rpos.second + dy[direction]);
		pair<int, int> nextbpos = make_pair(ball.bpos.first + dx[direction], ball.bpos.second + dy[direction]);

		if (rcomplete == false && rstop == false)
		{
			if (iswall[nextrpos.first][nextrpos.second])
				rstop = true;
		}

		if (bstop == false)
		{
			if (iswall[nextbpos.first][nextbpos.second])
				bstop = true;
		}

		if (rstop == false && nextrpos == ball.bpos && bstop)
			rstop = true;
		if (rcomplete == false && bstop == false && nextbpos == ball.rpos && rstop)
			bstop = true;

		if (rstop == false && rcomplete == false)
		{
			ball.rpos.first = nextrpos.first;
			ball.rpos.second = nextrpos.second;
		}
		if (bstop == false)
		{
			ball.bpos.first = nextbpos.first;
			ball.bpos.second = nextbpos.second;
		}

		if (nextbpos.first == goalPos.first && nextbpos.second == goalPos.second) return ball;
		if (nextrpos.first == goalPos.first && nextrpos.second == goalPos.second)
		{
			rstop = true;
			rcomplete = true;
		}
	}

	return ball;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			if (input[j] == '#') iswall[i][j] = true;

			if (input[j] == 'R')
			{
				initBallPos.rpos.first = i;
				initBallPos.rpos.second = j;
			}
			else if (input[j] == 'B')
			{
				initBallPos.bpos.first = i;
				initBallPos.bpos.second = j;
			}
			else if (input[j] == 'O')
			{
				goalPos.first = i;
				goalPos.second = j;
			}
		}
	}

	int count = -1;
	queue<pair<ballpos, int>> ballq;
	ballq.push({ initBallPos, 0 });

	while (ballq.empty() == false)
	{
		ballpos cur = ballq.front().first;
		int depth = ballq.front().second;
		ballq.pop();

		if (depth > 10)
		{
			count = -1;
			break;
		}

		if (cur.bpos == goalPos) continue;
		if (cur.rpos == goalPos)
		{
			count = depth;
			break;
		}


		for (int i = 0; i < 4; i++)
		{
			ballpos npos = moveball(cur, i);
			if (visit[npos.rpos.first][npos.rpos.second][npos.bpos.first][npos.bpos.second]) continue;
			visit[npos.rpos.first][npos.rpos.second][npos.bpos.first][npos.bpos.second] = true;
			ballq.push({ npos, depth + 1 });
		}
	}

	cout << count;
}