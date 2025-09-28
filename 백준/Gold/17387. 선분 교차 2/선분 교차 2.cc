#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
#define INF 1e9
#define LL long long

pair<LL, LL> l1, l2, l3, l4;

LL get_ccw(pair<LL, LL> x, pair<LL, LL> y, pair<LL, LL> z)
{
	LL ans = 0;
	ans += (x.first * y.second + y.first * z.second + z.first * x.second);
	ans -= (y.first * x.second + z.first * y.second + x.first * z.second);
	if (ans > 0) return 1;
	else if (ans == 0) return 0;
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> l1.first >> l1.second >> l2.first >> l2.second;
	cin >> l3.first >> l3.second >> l4.first >> l4.second;

	LL a = get_ccw(l1, l2, l3) * get_ccw(l1, l2, l4);
	LL b = get_ccw(l3, l4, l1) * get_ccw(l3, l4, l2);

	if (a == 0 && b == 0) 
	{
		if (l1 > l2)
		{
			pair<LL, LL> temp = l1;
			l1 = l2;
			l2 = temp;
		}
		if (l3 > l4)
		{
			pair<LL, LL> temp = l3;
			l3 = l4;
			l4 = temp;
		}

		if (l2 >= l3 && l1 <= l4) 
		{
			cout << "1";
			return 0;
		}

		cout << "0";
		return 0;
	}
	else if (a <= 0 && b <= 0) 
	{
		cout << "1";
		return 0;
	}
	
	cout << "0";
}