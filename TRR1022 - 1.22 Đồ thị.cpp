#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
const int INF = 10000;
int main()
{
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    if (t == 1)
    {
        vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
        for (auto [u, v, w] : edges)
        {
            outDeg[u]++;
            inDeg[v]++;
        }
        for (int i = 1; i <= n; ++i)
            cout << inDeg[i] << " " << outDeg[i] << endl;
    }
    else if (t == 2)
    {
        vector<vector<int>> c(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; ++i) c[i][i] = 0;
        for (auto [u, v, w] : edges) c[u][v] = w;
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cout << c[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
