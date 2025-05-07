#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int n, m, k;
long long a, b, c;
long long answer = 0;
long long arr[1000001];
long long tree[1000000 * 4 + 1];


void build(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(start, mid, node * 2);
	build(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long value)
{
	if (start == end)
	{
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	if (start <= index && index <= mid)
	{
		update(start, mid, node * 2, index, value);
	}
	else
	{
		update(mid + 1, end, node * 2 + 1, index, value);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	build(1, n, 1);

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, n, 1, b, c);
		}
		else if (a == 2)
		{
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
}