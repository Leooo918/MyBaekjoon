#include<iostream>

using namespace std;


int main()
{
	float input;
	cin >> input;

	float p = 1, q = 1;

	while (abs((p / q) - input) > 0.000001f) 
	{
		if ((p / q) > input)
			q++;
		else
			p++;
	}

	cout << ("YES") << '\n' << p << " " << q;
}