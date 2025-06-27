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

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].first >> edges[i].second;
  
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
        vector<vector<int>> adj(n + 1);
        for (auto [u, v] : edges) adj[u].push_back(v);
        cout << n << '\n';
        for (int i = 1; i <= n; ++i)
        {
            sort(adj[i].begin(), adj[i].end());
            cout << adj[i].size();
            for (int v : adj[i]) cout << ' ' << v;
            cout << '\n';
        }
    }
    return 0;
}
