#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int n;
long long answer = 0;
long long arr[100002];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		answer = 0;
		stack<long long> tree;	
		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		tree.push(0);

		for (int i = 1; i <= n + 1; i++)
		{
			while (!tree.empty() && (arr[tree.top()] > arr[i]))
			{
				int check = tree.top();
				tree.pop();
				answer = max(answer, arr[check] * (i - tree.top() - 1));
			}
			tree.push(i);
		}

		cout << answer << '\n';
	}
}