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
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            int indeg = 0, outdeg = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (a[j][i]) indeg++;
                if (a[i][j]) outdeg++;
            }
            cout << indeg << ' ' << outdeg << endl;
        }
    }
    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> adj;
            for (int j = 1; j <= n; ++j)
                if (a[i][j]) adj.push_back(j);
            
            cout << adj.size();
            for (int v : adj) cout << ' ' << v;
            cout << endl;
        }
    }
    return 0;
}
