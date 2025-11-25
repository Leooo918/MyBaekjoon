#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include<unordered_set>

using namespace std;

struct matrix
{
public:
	long long value[8][8];

	matrix(long long init[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				value[i][j] = init[i][j];
			}
		}
	}
	matrix()
	{
		memset(value, 0, sizeof(value));
	}

	matrix operator*(const matrix& b)
	{
		matrix result;
		memset(result.value, 0, sizeof(result.value));
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					result.value[i][j] =
						(result.value[i][j] + (value[i][k] * b.value[k][j])) % 1000000007;
				}
			}
		}
		return result;
	}
};

long long g[8][8]{ {0,1,1,0,0,0,0,0,},{1,0,1,1,0,0,0,0,},{1,1,0,1,1,0,0,0,},{0,1,1,0,1,1,0,0,},{0,0,1,1,0,1,1,0,},{0,0,0,1,1,0,0,1,},{0,0,0,0,1,0,0,1,},{0,0,0,0,0,1,1,0,} };

//vector<int> graph[8]{ {1,2},{0,2,3},{0,1,3,4},{1,2,4,5},{2,3,5,6},{3,4,7},{4,7},{5,6} };



matrix fastpow(matrix a, int b)
{
	if (b == 0)
	{
		matrix identity;
		for (int i = 0; i < 8; i++)
		{
			identity.value[i][i] = 1;
		}
		return identity;
	}

	if (b % 2 == 0)
	{
		matrix val = fastpow(a, b / 2);
		return val * val;
	}
	else
	{
		matrix val = fastpow(a, (b - 1) / 2);
		return val * val * a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int d;
	cin >> d;


	if (d <= 1)
	{
		cout << 0;
	}
	else
	{
		matrix base = matrix(g);
		matrix result = fastpow(base, d);

		cout << result.value[0][0];
	}
}