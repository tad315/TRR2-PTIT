#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int main()
{
    fast;

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<tuple<int, int, int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    if (t == 1)
    {
        vector<int> deg(n + 1, 0);
        for (auto &e : edges)
        {
            int u, v, w;
            tie(u, v, w) = e;
            deg[u]++;
            deg[v]++;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << deg[i] << (i < n ? ' ' : '\n');
        }
    }
    else if (t == 2)
    {
        const int INF = 10000;
        vector<vector<int>> c(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; ++i)
            c[i][i] = 0;
        for (auto &e : edges)
        {
            int u, v, w;
            tie(u, v, w) = e;
            c[u][v] = w;
            c[v][u] = w;
        }
        cout << n << '\n';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << c[i][j] << (j < n ? ' ' : '\n');
            }
        }
    }

    return 0;
}
