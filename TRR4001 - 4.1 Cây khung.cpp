#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int t, n, s;
int a[105][105];
bool vis[105];
vector<pair<int, int>> tree;

void dfs(int u)
{
    vis[u] = 1;
    for (int v = 1; v <= n; ++v)
    {
        if (a[u][v] && !vis[v])
        {
            tree.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[v][i] && !vis[i])
            {
                vis[i] = 1;
                tree.push_back({v, i});
                q.push(i);
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    cin >> t >> n >> s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    memset(vis, 0, sizeof(vis));
    tree.clear();

    if (t == 1) dfs(s);
    else bfs(s);

    if (tree.size() == n - 1)
    {
        cout << n - 1 << endl;
        for (auto e : tree) cout << min(e.first, e.second) << " " << max(e.first, e.second) << endl;
    }
    else cout << 0 << endl;
    return 0;
}
