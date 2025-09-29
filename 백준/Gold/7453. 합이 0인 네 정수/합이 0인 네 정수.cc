#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
#define INF 1e9
#define LL long long

int n;
LL number[4001][4];
LL mul[16000001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number[i][0] >> number[i][1] >> number[i][2] >> number[i][3];
	}

	vector<LL> mulvec;
	mulvec.reserve(n * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mul[i * n + j] = number[i][0] + number[j][1];
			mulvec.push_back(number[i][2] + number[j][3]);
		}
	}

	sort(mulvec.begin(), mulvec.end());

	LL count = 0;
	

	for (int i = 0; i < (n * n); i++)
	{
		LL target = -mul[i];

		auto lower = lower_bound(mulvec.begin(), mulvec.end(), target);
		auto upper = upper_bound(mulvec.begin(), mulvec.end(), target);

		count += (upper - lower);
	}

	cout << count;
}