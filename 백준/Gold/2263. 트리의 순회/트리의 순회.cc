#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>

using namespace std;
#define INF 1e9
#define LL long long

int Index[100001];
int inorder[100001];
int postorder[100001];
int n;

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return;

    int rootIndex = Index[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << inorder[rootIndex] << ' ';

    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        Index[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }

	getPreOrder(1, n, 1, n);
}