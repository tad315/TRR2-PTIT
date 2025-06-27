#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    boost;
    int t, n;
    cin >> t >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            if (v < 1 || v > n) return 0;            
            adj[i].push_back(v);
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i)
            cout << adj[i].size() << ' ';
        cout << endl;
    }
    else if (t == 2)
    {
        set<pair<int, int>> edges;
        for (int u = 1; u <= n; ++u)
            for (int v : adj[u])
                if (u < v)
                    edges.emplace(u, v);

        int m = edges.size();
        cout << n << ' ' << m << endl;

        vector<pair<int, int>> E(all(edges));
        vector<vector<int>> mat(n + 1, vector<int>(m, 0));
        for (int j = 0; j < m; ++j)
        {
            auto [u, v] = E[j];
            mat[u][j] = mat[v][j] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j) cout << mat[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
