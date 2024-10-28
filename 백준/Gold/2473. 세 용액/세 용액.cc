#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int n;
long long int minimum = 9223372036854775807;
long long int arr[100001];
long long int ans[3];

int f(long long int x)
{
	int left = 0, right = n - 1, mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (arr[mid] == -x) return mid;

		if (arr[mid] > -x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (left >= n) return right;
	else if (right < 0) return left;

	return abs(arr[left] + x) <= abs(arr[right] + x) ? left : right;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int k;
	long long int diff;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			k = f(arr[i] + arr[j]);
			diff = arr[i] + arr[j] + arr[k];

			if (k == i || k == j) continue;

			if (abs(diff) < minimum)
			{
				minimum = abs(diff);
				ans[0] = arr[i];
				ans[1] = arr[j];
				ans[2] = arr[k];
			}
		}
		if (minimum == 0) break;
	}

	sort(ans, ans + 3);
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}