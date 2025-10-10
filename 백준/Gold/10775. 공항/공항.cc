#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>

using namespace std;
#define INF 1e9
#define LL long long

int G, P;
int airplane[100001];
int gate[100001];
bool fail = false;

int findg(int g)
{
	if (gate[g] == g) return g;
	return gate[g] = findg(gate[g]);
}

bool trydocking(int g)
{
	int pg = findg(g);
	if (pg == 0) return false;

	gate[pg] = findg(pg - 1);
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	cin >> G >> P;

	for (int i = 1; i <= G; i++) gate[i] = i;

	for (int i = 0; i < P; i++)
	{
		cin >> airplane[i];

		if (fail) continue;

		if (trydocking(airplane[i])) count++;
		else fail = true;
	}

	cout << count;
}