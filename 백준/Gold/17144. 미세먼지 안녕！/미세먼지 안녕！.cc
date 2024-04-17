#include <iostream>
#include<tuple>
#include<queue>
#include<cmath>
#include<string.h>

using namespace std;

int r, c, t;
int answer = 0;
int arr[51][51]{ 0 };
int add[51][51]{ 0 };
int upAirC = -1;
int downAirC = -1;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void f()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cnt = 0;

			if (arr[i][j] == 0 || arr[i][j] == -1) continue;

			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || y < 0 || x >= r || y >= c || arr[x][y] == -1) continue;

				add[x][y] += (arr[i][j] / 5);
				cnt++;
			}
			add[i][j] -= (cnt * (arr[i][j] / 5));
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] += add[i][j];
			add[i][j] = 0;
		}
	}
}

void ff()
{
	answer -= arr[upAirC - 1][0];
	answer -= arr[downAirC + 1][0];

	for (int i = upAirC - 1; i > 0; i--)
		arr[i][0] = arr[i - 1][0];

	for (int i = 0; i < c - 1; i++)
		arr[0][i] = arr[0][i + 1];

	for (int i = 1; i <= upAirC; i++)
		arr[i - 1][c - 1] = arr[i][c - 1];

	for (int i = c - 1; i > 1; i--)
		arr[upAirC][i] = arr[upAirC][i - 1];

	arr[upAirC][1] = 0;


	for (int i = downAirC + 1; i < r - 1; i++)
		arr[i][0] = arr[i + 1][0];

	for (int i = 0; i < c - 1; i++)
		arr[r - 1][i] = arr[r - 1][i + 1];

	for (int i = r - 1; i >= downAirC; i--)
		arr[i][c - 1] = arr[i - 1][c - 1];

	for (int i = c - 1; i > 1; i--)
		arr[downAirC][i] = arr[downAirC][i - 1];

	arr[downAirC][1] = 0;
}

int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);


	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
			{
				if (upAirC == -1)
					upAirC = i;
				else
					downAirC = i;
			}
			else
				answer += arr[i][j];
		}
	}

	while (t--)
	{
		f();
		ff();
	}

	cout << answer;
}
