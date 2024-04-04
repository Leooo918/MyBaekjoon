#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, m, chickenNum; 
int answer = 0x3f3f3f3f;
int map[51][51];
int v[13];

vector<pair<int, int>> house; 
vector<pair<int, int>> chicken;
vector<pair<int, int>> temp;

void f(int idx, int cnt)
{
	if (cnt == m)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int x = house[i].first;
			int y = house[i].second;
			int d = 0x3f3f3f3f;

			for (int j = 0; j < temp.size(); j++)
			{
				int xx = temp[j].first;
				int yy = temp[j].second;
				int dist = abs(xx - x) + abs(yy - y);

				d = min(d, dist);
			}
			sum = sum + d;
		}

		answer = min(answer, sum);
		return;
	}

	for (int i = idx; i < chickenNum; i++)
	{
		if (v[i] == 1) continue;
		v[i] = 1;
		temp.push_back(chicken[i]);
		f(i, cnt + 1);
		v[i] = 0;
		temp.pop_back();
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	chickenNum = chicken.size();

	f(0, 0);
	cout << answer;	
}