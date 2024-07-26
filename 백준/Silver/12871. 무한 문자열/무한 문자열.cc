#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int gcd(int n, int m)
{
	if (n == 0) return m;
	return gcd(m % n, n);
}

int main()
{
	string str1, str2;

	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	int lcm = (n * m) / gcd(n, m);

	string s,ss;

	while (s.size() != lcm)
	{
		s += str1;
	}

	while (ss.size() != lcm)
	{
		ss += str2;
	}

	if (s == ss)cout << 1;
	else cout << 0;
}