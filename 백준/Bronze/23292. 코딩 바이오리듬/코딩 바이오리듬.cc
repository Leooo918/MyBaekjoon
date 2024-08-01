#include <iostream>
#include<math.h>

using namespace std;

long long biorhythm(long long a, long long b)
{
    long long ans = 1;
    long long temp;

    temp = 0;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10;
    b /= 10;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10;
    b /= 10;
    ans *= temp;

    temp = 0;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    ans *= temp;

    temp = 0;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    temp += (a % 10 - b % 10) * (a % 10 - b % 10);
    a /= 10; b /= 10;
    ans *= temp;

    return ans;
}

int main() {
    long long b, N, i, now;
    long long mx = -1;
    long long d = 2e9;

    cin >> b >> N;

    for (i = 0; i < N; i++)
    {
        cin >> now;
        long long num = biorhythm(b, now);
        if (mx < num)
        {
            mx = num;
            d = now;
        }
        if (mx == num)
        {
            if (now < d)
            {
                d = now;
            }
        }
    }

    cout << d;
}