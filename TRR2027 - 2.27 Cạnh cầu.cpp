#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int N = 100;
int n, a[N][N];
bool vis[N];
int d[N], low[N], par[N], t;
vector<pair<int, int>> bridges;

void dfs(int u)
{
    vis[u] = 1;
    d[u] = low[u] = ++t;

    for (int v = 0; v < n; ++v)
    {
        if (!a[u][v]) continue;
        if (!vis[v])
        {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > d[u]) bridges.emplace_back(min(u, v) + 1, max(u, v) + 1);
        }
        else if (v != par[u])
            low[u] = min(low[u], d[v]);
        
    }
}

void findBridges()
{
    fill(vis, vis + n, 0);
    fill(par, par + n, -1);
    t = 0;

    for (int i = 0; i < n; ++i)
        if (!vis[i]) dfs(i);

    sort(bridges.begin(), bridges.end());

    freopen("TK.OUT", "w", stdout);
    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges) cout << u << ' ' << v << '\n';
}

int main()
{
    freopen("TK.INP", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    findBridges();
    return 0;
}
