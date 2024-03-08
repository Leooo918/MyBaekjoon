#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long a, b, c;
long long e;


long long power(long long d) {
	if (d == 0) return 1;
	if (d == 1) return a % c;

	e = power(d / 2) % c;
	if (d % 2 == 0) return e * e % c;
	return e * e % c * a % c;
}


int main(int argc, char** argv)
{
	cin >> a >> b >> c;
	long long answer = power(b);

	cout << answer;
}