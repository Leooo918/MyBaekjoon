#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, k;
	cin >> s >> k;

	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			s.erase(s.begin() + i--);
		}
	}

	if (s.find(k) == string::npos)
		cout << 0;
	else
		cout << 1;
}