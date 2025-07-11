#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n;
int mapArr[21][21];
int arrTemp[21][21];
int direction[5];
int answer = 0;

void MoveLeft()
{
	//제일 왼쪽으로 이동
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arrTemp[i][j] == 0) continue;

			int x = j;
			for (int k = j - 1; k >= 0; k--)
			{
				if (arrTemp[i][k] == 0) x = k;
			}

			arrTemp[i][x] = arrTemp[i][j];
			if (x != j)arrTemp[i][j] = 0;
		}
	}
	//합치기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arrTemp[i][j] == arrTemp[i][j + 1])
			{
				arrTemp[i][j] += arrTemp[i][j + 1];
				arrTemp[i][j + 1] = 0;
			}
		}
	}
	//다시 밀기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arrTemp[i][j] == 0) continue;

			int x = j;
			for (int k = j - 1; k >= 0; k--)
			{
				if (arrTemp[i][k] == 0) x = k;
			}

			arrTemp[i][x] = arrTemp[i][j];
			if (x != j)arrTemp[i][j] = 0;
		}
	}
}

void MoveRight()
{
	//제일 오른쪽으로 이동
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (arrTemp[i][j] == 0) continue;

			int x = j;
			for (int k = j + 1; k < n; k++)
			{
				if (arrTemp[i][k] == 0) x = k;
			}

			arrTemp[i][x] = arrTemp[i][j];
			if (x != j)arrTemp[i][j] = 0;
		}
	}
	//합치기
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (arrTemp[i][j] == arrTemp[i][j - 1])
			{
				arrTemp[i][j] += arrTemp[i][j - 1];
				arrTemp[i][j - 1] = 0;
			}
		}
	}
	//다시 밀기
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (arrTemp[i][j] == 0) continue;

			int x = j;
			for (int k = j + 1; k < n; k++)
			{
				if (arrTemp[i][k] == 0) x = k;
			}

			arrTemp[i][x] = arrTemp[i][j];
			if (x != j)arrTemp[i][j] = 0;
		}
	}
}

void MoveUp()
{
	//제일 위쪽으로 이동
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arrTemp[j][i] == 0) continue;

			int y = j;
			for (int k = j - 1; k >= 0; k--)
			{
				if (arrTemp[k][i] == 0) y = k;
			}

			arrTemp[y][i] = arrTemp[j][i];
			if (y != j)arrTemp[j][i] = 0;
		}
	}
	//합치기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arrTemp[j][i] == arrTemp[j + 1][i])
			{
				arrTemp[j][i] += arrTemp[j + 1][i];
				arrTemp[j + 1][i] = 0;
			}
		}
	}
	//다시 밀기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arrTemp[j][i] == 0) continue;

			int y = j;
			for (int k = j - 1; k >= 0; k--)
			{
				if (arrTemp[k][i] == 0) y = k;
			}

			arrTemp[y][i] = arrTemp[j][i];
			if (y != j)arrTemp[j][i] = 0;
		}
	}
}

void MoveDown()
{
	//제일 아래쪽으로 이동
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (arrTemp[j][i] == 0) continue;

			int y = j;
			for (int k = j + 1; k < n; k++)
			{
				if (arrTemp[k][i] == 0) y = k;
			}

			arrTemp[y][i] = arrTemp[j][i];
			if (y != j)arrTemp[j][i] = 0;
		}
	}
	//합치기
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (arrTemp[j][i] == arrTemp[j - 1][i])
			{
				arrTemp[j][i] += arrTemp[j - 1][i];
				arrTemp[j - 1][i] = 0;
			}
		}
	}
	//다시 밀기
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (arrTemp[j][i] == 0) continue;

			int y = j;
			for (int k = j + 1; k < n; k++)
			{
				if (arrTemp[k][i] == 0) y = k;
			}

			arrTemp[y][i] = arrTemp[j][i];
			if (y != j)arrTemp[j][i] = 0;
		}
	}
}


void f(int dir, int count)
{
	if (count == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arrTemp[i][j] = mapArr[i][j];
			}
		}

		for (int i = 0; i < 5; i++)
		{
			switch (direction[i])
			{
			case 0:
				MoveLeft();
				break;
			case 1:
				MoveRight();
				break;
			case 2:
				MoveUp();
				break;
			case 3:
				MoveDown();
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				answer = max(answer, arrTemp[i][j]);
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		direction[count] = i;
		f(i, count + 1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mapArr[i][j];
		}
	}

	f(0, 0);
	cout << answer;
}