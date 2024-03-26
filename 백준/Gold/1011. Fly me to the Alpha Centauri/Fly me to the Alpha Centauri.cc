#include <iostream>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int t;
	int a, b;
	int length, d;
	int answer = 0;

	cin >> t;

	while (t--)
	{
		cin >> a >> b;

		length = b - a;
		d = sqrt(length);

		answer = 2 * d;

		if (pow(d, 2) == length) answer--;
		if (length > d * (d + 1)) answer++;

		cout << answer << "\n";
	}

}