#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct shark
{
	int r, c, s, d, z, id;
};

int R, C, M;
vector<shark> sharks;

vector<shark> nextSharks;
int temp[101][101];

void move(shark& sh, int R, int C)
{
	if (sh.s == 0) return;

	if (sh.d <= 2)
	{
		int cycle = (R - 1) * 2;
		if (cycle > 0)
		{
			int s = sh.s % cycle;
			for (int i = 0; i < s; ++i)
			{
				if (sh.d == 1)
				{
					if (sh.r == 1) {
						sh.r++;
						sh.d = 2;
					}
					else {
						sh.r--;
					}
				}
				else
				{
					if (sh.r == R) {
						sh.r--;
						sh.d = 1;
					}
					else {
						sh.r++;
					}
				}
			}
		}
	}
	else
	{
		int cycle = (C - 1) * 2;
		if (cycle > 0)
		{
			int s = sh.s % cycle;
			for (int i = 0; i < s; ++i)
			{
				if (sh.d == 3)
				{
					if (sh.c == C) {
						sh.c--;
						sh.d = 4;
					}
					else {
						sh.c++;
					}
				}
				else
				{
					if (sh.c == 1) {
						sh.c++;
						sh.d = 3;
					}
					else {
						sh.c--;
					}
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;
	sharks.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
		sharks[i].id = i;
	}

	long long ans = 0;

	for (int i = 1; i <= C; ++i)
	{
		//낚시
		int sharkIdx = -1;
		int r = R + 1;

		for (int j = 0; j < sharks.size(); ++j)
		{
			if (sharks[j].c == i)
			{
				if (sharks[j].r < r)
				{
					r = sharks[j].r;
					sharkIdx = j;
				}
			}
		}

		if (sharkIdx != -1)
		{
			ans += sharks[sharkIdx].z;
			sharks.erase(sharks.begin() + sharkIdx);
		}

		// 상어 이동
		for (auto& sh : sharks) { move(sh, R, C); }

		// 상어 잡아먹기
		if (sharks.empty()) continue;

		// 크기 순으로 내림차순 정렬
		sort(sharks.begin(), sharks.end(), [](const shark& a, const shark& b) { return a.z > b.z; });

		memset(temp, -1, sizeof(temp));

		for (shark sh : sharks)
		{
			if (temp[sh.r][sh.c] == -1)
			{
				temp[sh.r][sh.c] = 1;
				nextSharks.push_back(sh);
			}
		}
		sharks = nextSharks;
		nextSharks.clear();
	}

	cout << ans;
}