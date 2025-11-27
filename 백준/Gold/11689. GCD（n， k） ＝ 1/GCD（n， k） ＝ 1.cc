#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include<unordered_set>
#include <cmath> 

using namespace std;

long long euler_phi(long long n)
{
	long long prime = n;
	long long composite = n;

	for (long long i = 2; i * i <= composite; i++)
	{
		if (composite % i == 0)
		{
			prime = prime / i * (i - 1);

			while (composite % i == 0)
			{
				composite /= i;
			}
		}
	}

	if (composite > 1)
	{
		prime = prime / composite * (composite - 1);
	}
	return prime;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;
	cout << euler_phi(n);
}