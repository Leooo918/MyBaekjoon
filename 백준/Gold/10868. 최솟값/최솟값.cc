#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int n, m;
long long a, b;
long long arr[100001];
long long minTree[400001];


void build(int start, int end, int node)
{
	if (start == end)
	{
		minTree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(start, mid, node * 2);
	build(mid + 1, end, node * 2 + 1);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

long long minquery(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) return 1000000001;
	if (start >= left && end <= right) return minTree[node];

	int mid = (start + end) / 2;
	return min(minquery(start, mid, node * 2, left, right), minquery(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	build(1, n, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << minquery(1, n, 1, a, b) << '\n';
	}
}