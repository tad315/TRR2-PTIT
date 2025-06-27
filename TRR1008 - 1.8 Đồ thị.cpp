#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;
    int t, n;
    cin >> t >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i) cout << adj[i].size() << " ";
    }
    else if (t == 2)
    {
        vector<pair<int, int>> e;
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, 0));

        for (int u = 1; u <= n; ++u)
        {
            for (int v : adj[u])
            {
                if (!vis[u][v] && !vis[v][u])
                {
                    e.push_back({min(u, v), max(u, v)});
                    vis[u][v] = vis[v][u] = 1;
                }
            }
        }
        sort(all(e));
        cout << n << " " << e.size() << endl;
        for (auto x : e)
            cout << x.first << " " << x.second << endl;
    }

    return 0;
}
