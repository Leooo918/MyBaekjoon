#include<iostream>
#include<algorithm>
#include<tuple>

using namespace std;


long long int f(long long int a, long long int b)
{
	if (a == 0 || b == 0) return a + b;
	if (a > b) return f(a % b, b);
	return f(b % a, a);
}

int main()
{
	long long int n, m;
	cin >> n >> m;

	if (n < 0) n *= -1;
	if (m < 0) m *= -1;

	if (n == 0 && m == 0)
	{
		cout << 0;
	}
	else if (f(n, m) == 1)
	{
		cout << 1;
	}
	else
	{
		cout << 2;
	}
}