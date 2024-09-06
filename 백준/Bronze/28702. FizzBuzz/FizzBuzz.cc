#include <iostream>
#include <queue>
#include<string>

using namespace std;
int main()
{
	string a, b, c;
	int answer;
	cin >> a >> b >> c;

	if (isdigit(a[0]))
	{
		answer = stoi(a) + 3;
	}
	if (isdigit(b[0]))
	{
		answer = stoi(b) + 2;
	}
	if (isdigit(c[0]))
	{
		answer = stoi(c) + 1;
	}

	if (answer % 3 == 0 && answer % 5 == 0)
	{
		cout << "FizzBuzz";
	}
	else if (answer % 3 == 0)
	{
		cout << "Fizz";
	}
	else if (answer % 5 == 0)
	{
		cout << "Buzz";
	}
	else
	{
		cout << answer;
	}
}
