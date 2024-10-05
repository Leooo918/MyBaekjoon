#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
	int n, m;
	vector<long long int> v;
	long long int input;

	cin >> n;

	long long int left = 0, mid, right = n - 1;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;

		bool exsist = false;
		while (left <= right)
		{
			mid = left + ((right - left) / 2);


			if (v[mid] > input)
			{
				right = mid - 1;
			}
			else if (v[mid] < input)
			{
				left = mid + 1;
			}
			else
			{
				exsist = true;
				break;
			}
		}

		left = 0;
		right = n - 1;
		cout << (exsist ? 1 : 0) << "\n";
	}
}