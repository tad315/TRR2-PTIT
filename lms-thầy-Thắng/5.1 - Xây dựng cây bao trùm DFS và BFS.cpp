#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define MAX 1005

int used[10000], pre[10000];
vector<vector<int>> a;
void DFS(int u)
{
    used[u] = 1;
    for (int it : a[u])
    {
        if (!used[it])
        {
            cout << min(it, u) << " " << max(it, u) << endl;
            DFS(it);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = 1;
    while (q.size())
    {
        int i = q.front();
        q.pop();
        for (int it : a[i])
        {
            if (!used[it])
            {
                cout << min(it, i) << " " << max(it, i) << endl;
                used[it] = 1;
                q.push(it);
            }
        }
    }
}

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    a.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x) a[i].pb(j);
        }
    }
    memset(used, 0, sizeof(used));
    cout << "DFS tree\n";
    DFS(k);
    memset(used, 0, sizeof(used));
    cout << "BFS tree\n";
    BFS(k);
}
