#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int n, m, k;
long long a, b, c, d;
long long answer = 0;
long long arr[1000001];
long long tree[4000001];
long long lazy[4000001];

void applylazy(int start, int end, int node)
{
	if (lazy[node] == 0) return;

	tree[node] += (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

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
	applylazy(start, end, node);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, long long value)
{
	applylazy(start, end, node);
	if (end < left || start > right) return;

	if (start >= left && end <= right)
	{
		tree[node] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
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
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			update(1, n, 1, b, c, d);
		}
		else if (a == 2)
		{
			cin >> b >> c;
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
}