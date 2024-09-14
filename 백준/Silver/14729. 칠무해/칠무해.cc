#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double input;
    vector<double> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
	    cin >> input;
	    v.push_back(input);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 7; i++)
    {
	    cout << fixed;
	    cout.precision(3);
	    cout << v[i] << '\n';
    }
}