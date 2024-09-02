#include<iostream>
#include<cstring>

using namespace std;

int n;
int arr[9][9];
bool visit[10];

bool f()
{
	for (int i = 0; i < 9; i++)
	{
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < 9; j++)
		{
			if (visit[arr[i][j]])
				return false;

			visit[arr[i][j]] = true;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < 9; j++)
		{
			if (visit[arr[j][i]])
				return false;

			visit[arr[j][i]] = true;
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			memset(visit, false, sizeof(visit));
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k;
					int y = j + l;
					if (visit[arr[x][y]])
						return false;

					visit[arr[x][y]] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	cin >> n;

	for (int m = 1; m <= n; m++)
	{

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> arr[i][j];
			}
		}

		cout << "Case " << m << ": ";

		if (f())
			cout << "CORRECT\n";
		else
			cout << "INCORRECT\n";
	}
}