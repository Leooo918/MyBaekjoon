#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
#define INF 1e9
#define LL long long

LL A, B;
LL sum[55];

LL f(LL x) {
	LL ans = x & 1;

	for (int i = 54; i > 0; i--)
	{
		if (x & (1LL << i))
		{
			ans += sum[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	sum[0] = 1;
	for (int i = 1; i < 55; i++)
	{
		sum[i] = sum[i - 1] * 2 + (1LL << i);
	}

	cout << (f(B) - f(A - 1));
}