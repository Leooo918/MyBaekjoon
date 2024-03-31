#include <iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<map>

using namespace std;

vector<int> v;

void f(int a, int b) 
{
	if (a >= b) return;
	if (a == b - 1)
	{
		cout << v[a] << "\n";
		return;
	}
	int idx = a + 1;
	while (idx < b)
	{
		if (v[a] < v[idx]) break;
		++idx;
	}

	f(a + 1, idx);
	f(idx, b);

	cout << v[a] << "\n";
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int n;
	while (cin >> n)
		v.push_back(n);

	f(0, v.size());
}