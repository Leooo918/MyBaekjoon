#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>

using namespace std;

map<long long, long long> lm;

long long f(long long n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (lm.count(n) > 0) return lm[n];

	if (n % 2 == 0) {
		long long m = n / 2;
		long long temp1 = f(m - 1); long long temp2 = f(m);
		lm[n] = ((2LL * temp1 + temp2) * temp2) % 1000000007;
		return lm[n];
	}
	long long m = (n + 1) / 2;
	long long temp1 = f(m); long long temp2 = f(m - 1);
	lm[n] = (temp1 * temp1 + temp2 * temp2) % 1000000007;
	return lm[n];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	long long n;
	cin >> n;

	long long answer = f(n);

	cout << answer;
}