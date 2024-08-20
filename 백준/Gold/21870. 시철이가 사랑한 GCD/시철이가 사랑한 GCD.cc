#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
bool arr[200001];

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int GCD(vector<int> v)
{
	if (v.size() <= 0) return 0;
	if (v.size() == 1) return v[0];

	if (v.size() % 2 == 0)
	{
		int l = v[0], r = v[v.size() / 2];
		vector<int> lv;
		vector<int> rv;

		lv.push_back(v[v.size() / 2]);
		rv.push_back(v[0]);

		for (int i = 1; i < v.size() / 2; i++)
		{
			rv.push_back(v[i]);
			l = gcd(l, v[i]);
		}

		for (int i = v.size() / 2 + 1; i < v.size(); i++)
		{
			lv.push_back(v[i]);
			r = gcd(r, v[i]);
		}

		return max(l + GCD(lv), r + GCD(rv));
	}
	else
	{
		int l = v[0];
		vector<int> lv;
		int r = v[v.size() - 1];
		vector<int> rv;

		rv.push_back(v[0]);
		lv.push_back(v[v.size() / 2]);

		for (int i = 1; i < v.size() / 2; i++)
		{
			l = gcd(l, v[i]);
			rv.push_back(v[i]);
		}

		for (int i = v.size() / 2 + 1; i < v.size(); i++)
		{
			r = gcd(r, v[i]);
			lv.push_back(v[i]);
		}

		return max(l + GCD(lv), r + GCD(rv));
	}
}

int main()
{
	int left = 0, right = 0;

	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	cout << GCD(v);
}
