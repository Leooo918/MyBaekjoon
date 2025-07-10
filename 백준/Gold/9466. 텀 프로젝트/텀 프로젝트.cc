#include <iostream>
#include<cstring>
#include <vector>

using namespace std;

int t;
int n;
int arr[100001];
int visit[100001];
int order[100001];
int answer = 0;

void dfs(int index, int currentOrder)
{
	if (visit[index] == 1) 
	{
		answer -= (currentOrder - order[index] + 1);
		return;
	}
	else if (visit[index] == -1) return;

	visit[index] = 1;
	order[index] = currentOrder + 1;
	dfs(arr[index], currentOrder + 1);
	visit[index] = -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;

		memset(visit, false, sizeof(visit));
		memset(order, false, sizeof(order));
		answer = n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (visit[i] != 0) continue;
			dfs(i, 0);
		}

		cout << answer << "\n";
	}
}