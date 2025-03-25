#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr;
bool notPrime[4000001];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 2; i * i <= n; i++)
	{
		if (notPrime[i] == false)
		{
			for (int j = i * 2; j <= n; j += i)
			{
				notPrime[j] = true;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (notPrime[i] == false)
			arr.push_back(i);
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int ans = 0;
	int size = arr.size();

	while (true)
	{
		if (sum > n)
		{
			sum -= arr[start++];
		}
		else if (end >= arr.size())
		{
			break;
		}
		else
		{
			sum += arr[end++];
		}


		if (sum == n) ans++;
	}

	cout << ans;
}