#include <iostream>
#include <vector>

using namespace std;
int main() {
    long long r, c, w;
    vector<vector<long long>> pascalTriangle;

    long long total = 0;

    cin >> r >> c >> w;

    for (int i = 1; i <= r + w; i++) 
    {
        vector<long long> a;
        
        for (int j = 0; j < i; j++) 
        {
            if(j == 0 || j == i - 1)
            {
                a.push_back(1);
            }
            else 
            {
                a.push_back(pascalTriangle[i - 2][j - 1] + pascalTriangle[i - 2][j]);
            }
        }
        
        pascalTriangle.push_back(a);
    }

    for (int i = 0; i < w; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            total += pascalTriangle[r + i - 1][c + j - 1];
        }
    }

    cout << total;

    return 0;
}