#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int main()
{
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> adj[i][j];
    }

    if (t == 1)
    {
        vector<int> deg_in(n + 1, 0), deg_out(n + 1, 0);

        for (int u = 1; u <= n; ++u)
        {
            deg_out[u] = adj[u].size();
            for (int v : adj[u]) ++deg_in[v];
        }

        for (int i = 1; i <= n; ++i)
            cout << deg_in[i] << ' ' << deg_out[i] << '\n';
    }
    else if (t == 2)
    {
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
        for (int u = 1; u <= n; ++u)
            for (int v : adj[u])
                matrix[u][v] = 1;
        cout << n << '\n';
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << matrix[i][j] << (j < n ? ' ' : '\n');
    }
    return 0;
}
