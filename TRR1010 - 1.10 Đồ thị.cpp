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

    int t, n;
    cin >> t >> n;
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    if (t == 1)
    {
        vector<int> deg(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j && c[i][j] != 10000)
                    ++deg[i];
        for (int i = 1; i <= n; ++i)
        {
            cout << deg[i];
            if (i < n) cout << " ";
            else cout << endl;
        }
    }
    else if (t == 2)
    {
        vector<tuple<int, int, int>> edges;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (c[i][j] != 10000)
                    edges.emplace_back(i, j, c[i][j]);
        int m = edges.size();
        cout << n << " " << m << endl;
        for (auto &e : edges){
            int u, v, w;
            tie(u, v, w) = e;
            cout << u << " " << v << " " << w << endl;
        }
    }
    return 0;
}
