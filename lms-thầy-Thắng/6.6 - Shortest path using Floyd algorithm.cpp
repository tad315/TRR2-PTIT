#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define MAX 1005

int n, m;
int D[505][505];
int par[505][505];

vector<int> trace_path(int u, int v)
{
    if (u == v) return {u};
    vector<int> path;
    while (v != u)
    {
        path.pb(v);
        v = par[u][v];
    }
    path.pb(u);
    reverse(all(path));
    return path;
}

int main()
{
    boost;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> D[i][j];
            if (i != j && !D[i][j]) D[i][j] = 1e9;
        }
    }

    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) par[u][v] = u;
        
    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (u != v && u != k && k != v && D[u][v] > D[u][k] + D[k][v])
                {
                    D[u][v] = D[u][k] + D[k][v];
                    par[u][v] = par[k][v];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] != 1e9)
            {
                cout << "K/c " << i + 1 << " -> " << j + 1 << " = " << D[i][j] << "; ";
                vector<int> ans = trace_path(i, j);
                for (int z = 0; z < ans.size(); z++)
                {
                    cout << ans[z] + 1;
                    if (z != ans.size() - 1) cout << " --> ";
                }
                cout << "\n";
            }
            else
            {
                cout << "K/c " << i + 1 << " -> " << j + 1 << " = " << 0 << "; " << i + 1;
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
