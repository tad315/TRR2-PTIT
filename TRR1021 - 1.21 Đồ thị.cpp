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

    int t, n;
    cin >> t >> n;

    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    if (t == 1) 
    {
        vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] != INF) 
                {
                    outDeg[i]++;
                    inDeg[j]++;
                }

        for (int i = 1; i <= n; ++i)
            cout << inDeg[i] << " " << outDeg[i] << endl;
    } 
    else if (t == 2) 
    {
        vector<tuple<int, int, int>> edges;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] != INF)
                    edges.emplace_back(i, j, c[i][j]);

        cout << n << " " << edges.size() << endl;
        for (auto [u, v, w] : edges)
            cout << u << " " << v << " " << w << endl;
    }
    return 0;
}
