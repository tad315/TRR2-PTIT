#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int main()
{
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; ++i) 
    {
        int k;
        cin >> k;
        while (k--) 
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
            edges.emplace_back(i, v);
        }
    }

    if (t == 1)
    {
        vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
        for (int u = 1; u <= n; ++u) 
        {
            outDeg[u] = adj[u].size();
            for (int v : adj[u]) inDeg[v]++;
        }
        for (int i = 1; i <= n; ++i) 
            cout << inDeg[i] << " " << outDeg[i] << "\n";
    } 
    else if (t == 2) 
    {
        int m = edges.size();
        cout << n << " " << m << "\n";

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                int u = edges[j].first;
                int v = edges[j].second;
                if (i == u) cout << "1 ";
                else if (i == v) cout << "-1 ";
                else cout << "0 ";
            }
            cout << "\n";
        }
    }
    return 0;
}
