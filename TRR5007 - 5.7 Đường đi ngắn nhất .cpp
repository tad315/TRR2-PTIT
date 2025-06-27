#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int INF = 1e9;

int n, s, t;
int c[105][105];
int d[105], trace[105];

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;

bool bellman_ford(int s)
{
    fill(d, d + n + 1, INF);
    fill(trace, trace + n + 1, -1);

    d[s] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto e : edges)
        {
            if (d[e.u] != INF && d[e.v] > d[e.u] + e.w)
            {
                d[e.v] = d[e.u] + e.w;
                trace[e.v] = e.u;
            }
        }
    }

    for (auto e : edges)
    {
        if (d[e.u] != INF && d[e.v] > d[e.u] + e.w)
            return false; 
        
    }
    return true;
}

vector<int> getPath(int t)
{
    vector<int> path;
    while (t != -1)
    {
        path.push_back(t);
        t = trace[t];
    }
    reverse(all(path));
    return path;
}

int main()
{
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] != 10000)
                edges.push_back({i, j, c[i][j]});
        }

    if (!bellman_ford(s)) cout << -1 << endl;
    
    else if (d[t] == INF) cout << 0 << endl;
    else
    {
        cout << d[t] << endl;
        vector<int> path = getPath(t);
        for (int v : path) cout << v << ' ';
        cout << endl;
    }
    return 0;
}
