#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int cost = 0;
int city[100001];
int road[100001];

int main()
{
	cin >> n;

	for (int i = 1; i < n; i++)
		cin >> road[i];

	for (int i = 1; i <= n; i++)
		cin >> city[i];

	int i = 1;
	while (i <= n)
	{
		int lc = cost;
		int cc = city[i];
		int r = 0;

		for (int j = i; j <= n; j++)
		{
			if (city[j] < cc)
			{
				cost += r * cc;
				i = j;
				break;
			}
			else
			{
				r += road[j];
			}
		}

		if (cost == lc)
		{
			for (int j = i; j <= n; j++)
				cost += cc * road[j];

			break;
		}
	}

	cout << cost;
}