#include<iostream>

using namespace std;

int main()
{
	unsigned long long int n, r;
	unsigned long long int cnt = 0;

	cin >> n >> r;

	if (n == 1)
	{
		cout << (r * 2);
		return  0;
	}

	cnt += (n - 1);
	cnt += (r * 2);

	cout << cnt;
}