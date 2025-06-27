#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].first >> edges[i].second;

    sort(edges.begin(), edges.end());

    if (t == 1)
    {
        vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
        for (auto [u, v] : edges)
        {
            ++outdeg[u];
            ++indeg[v];
        }
        for (int i = 1; i <= n; ++i)
            cout << indeg[i] << ' ' << outdeg[i] << '\n';
    }
    else if (t == 2)
    {
        vector<vector<int>> matrix(n + 1, vector<int>(m, 0));
        for (int j = 0; j < m; ++j)
        {
            int u = edges[j].first, v = edges[j].second;
            matrix[u][j] = 1;
            matrix[v][j] = -1;
        }

        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j)
                cout << matrix[i][j] << (j < m - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
