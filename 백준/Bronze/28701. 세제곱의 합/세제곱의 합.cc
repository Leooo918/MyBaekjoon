#include <iostream>
#include<math.h>
using namespace std;


int main() {
    int n, sum, a; 
    cin >> n;


    sum = n * (n + 1) / 2;
     a = sum * sum;

    int b = 0;
    for (int i = 1; i <= n; i++)
        b += pow(i, 3);

    cout << sum << "\n" << a << "\n" << b << "\n";
}