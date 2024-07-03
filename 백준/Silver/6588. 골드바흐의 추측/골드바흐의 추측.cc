#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


bool che[1000001] = {false};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (long long int i = 2; i < 1000001; i++)
	{
		if (che[i] == true) continue;

		for (long long int j = i * i; j < 1000001; j += i)
		{
			che[j] = true;
		}
	}

	int n;
	int a, b;
	bool isPrime;

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 3; i < n; i += 2)
		{
			a = i;
			b = n - a;
			isPrime = che[a] || che[b];

			if (isPrime == true) continue;

			cout << n << " = " << a << " + " << b << '\n';
			break;
		}
	}
}