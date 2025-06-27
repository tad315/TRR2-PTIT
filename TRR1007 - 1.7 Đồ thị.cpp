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
    vector<int> deg(n + 1, 0);
    int mt[101][101] = {0};

    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
            ++deg[i];
            mt[i][v] = 1;
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i) cout << deg[i] << " ";
    }
    
    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) cout << mt[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
