#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int n, answer, cnt;
bool visit[11][11];
bool r[21], l[21];


void func(int x, int y, int color)
{
	if (x > n)
	{
		answer = max(answer, cnt);
		return;
	}

	if (visit[x][y] && !r[x - y + 10] && !l[x + y] && (x + y) % 2 == color)
	{
		cnt++;
		r[x - y + 10] = true;
		l[x + y] = true;

		func(x + y / n, y % n + 1, color);

		cnt--;
		r[x - y + 10] = false;
		l[x + y] = false;
	}

	func(x + y / n, y % n + 1, color);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> visit[i][j];
		}
	}

	int total = 0;

	func(1, 1, 0);
	total += answer;
	answer = 0;

	func(1, 2, 1);
	total += answer;

	cout << total;
}