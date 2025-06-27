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
    int a[105][105];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            int degree = 0;
            for (int j = 1; j <= n; ++j) degree += a[i][j];
            cout << degree << " ";
        }
        cout << endl;
    }
    else if (t == 2)
    {
        vector<pair<int, int>> edges;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (a[i][j] == 1) edges.push_back({i, j});
            }
        }
        cout << n << " " << edges.size() << endl;
        for (auto &e : edges) cout << e.first << " " << e.second << endl;        
    }
    return 0;
}
