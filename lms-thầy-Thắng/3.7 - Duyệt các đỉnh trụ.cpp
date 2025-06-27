#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 100;
int n;
vector<int> g[MAXN]; 
bool vis[MAXN];

void dfs(int u, int skip)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v] && v != skip) dfs(v, skip);
    }
}

int tplt(int skip)
{
    fill(vis, vis + n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != skip && !vis[i])
        {
            dfs(i, skip);
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    int a[MAXN][MAXN];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j]) g[i].pb(j);
        }

    int baseCC = tplt(-1);
    vector<int> res;

    for (int i = 0; i < n; ++i)
        if (tplt(i) > baseCC) res.pb(i + 1);
    

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << (i + 1 < res.size() ? " " : "");
    return 0;
}
