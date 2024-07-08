#include<iostream>
#include<string>

using namespace std;

int n, m;
int cnt = 0;
int arr[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
			{
				int temp = arr[i][j];

				for (int k = j; k < m; k++)
				{
					if (arr[i][k] == 0) break;

					if (arr[i][k] == temp)
						arr[i][k] = 0;
				}

				cnt++;
			}
		}
	}

	cout << cnt;
}