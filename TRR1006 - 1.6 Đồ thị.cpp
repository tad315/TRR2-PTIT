#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int MAX_N = 105, MAX_M = 5000;

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;

    int t, n, m;
    cin >> t >> n >> m;

    int u[MAX_M], v[MAX_M];
    int deg[MAX_N] = {0};
    int mt[MAX_N][MAX_M] = {0};

    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        deg[u[i]]++;
        deg[v[i]]++;
        mt[u[i]][i] = 1;
        mt[v[i]][i] = 1;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg[i];
            if (i != n) cout << " ";
        }
        cout << endl;
    }
    else if (t == 2)
    {
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << mt[i][j];
                if (j != m - 1) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
