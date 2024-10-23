#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int n;
long long int minimum = 9223372036854775807;
long long int arr[100001];
long long int x = 0, y = 0;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	int left = 0, right = n - 1;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	while (left < right)
	{
		int diff = arr[right] + arr[left];

		if (abs(diff) < minimum)
		{
			minimum = abs(diff);
			x = arr[left];
			y = arr[right];

			if (diff == 0) break;
		}

		if (diff <= 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << x << " " << y;
}