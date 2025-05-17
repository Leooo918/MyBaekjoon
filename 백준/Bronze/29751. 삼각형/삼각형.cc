#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    float a,b;
    cin >> a>> b;
    
    cout << fixed;
	cout.precision(1);
    cout << ((a * b) / 2);
}
