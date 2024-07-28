#include<iostream>
#include<stack>

using namespace std;

int gcd(int n, int m)
{
	if (n == 0) return m;
	return gcd(m % n, n);
}

int main()
{
	string str;
	char input, temp;
	int cnt;

	stack<char> l, r;

	cin >> str >> cnt;

	for (int i = 0; i < str.size(); i++)
	{
		l.push(str[i]);
	}

	for (int i = 0; i < cnt; i++)
	{
		cin >> input;

		switch (input)
		{
		case 'L':
			if (l.empty()) break;

			temp = l.top();
			l.pop();
			r.push(temp);
			break;
		case 'D':
			if (r.empty()) break;

			temp = r.top();
			r.pop();
			l.push(temp);
			break;
		case 'B':
			if (l.empty()) break;

			l.pop();
			break;
		case 'P':
			cin >> input;
			l.push(input);
			break;
		}
	}

	while (!l.empty())
	{
		r.push(l.top());
		l.pop();
	}

	while (!r.empty())
	{
		cout << r.top();
		r.pop();
	}
}