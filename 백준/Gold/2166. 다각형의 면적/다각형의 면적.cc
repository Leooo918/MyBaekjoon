#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <tuple>

using namespace std;


int main(int argc, char** argv)
{
    int n;

    cin >> n;
    vector<pair<long double, long double>> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    long double result = 0;
    pair<long double, long double> origin = points[0];
    
    for (int i = 1; i < n - 1; i++)
    {
        result += (points[i].first - origin.first) * (points[i + 1].second - origin.second)
            - (points[i].second - origin.second) * (points[i + 1].first - origin.first);
    }

    result /= 2.0f;

    if (result < 0) result *= -1;

    cout << fixed;
    cout.precision(1);
    cout << result;
}