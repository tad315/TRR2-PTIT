#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, m;
int p[105];

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &e) const
    {
        if (w != e.w) return w < e.w;
        if (u != e.u) return u < e.u;
        return v < e.v;
    }
};

vector<Edge> edges, mst;

int find(int u)
{
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

bool unionSet(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;
    p[u] = v;
    return true;
}

int kruskal()
{
    sort(all(edges));
    mst.clear();
    for (int i = 1; i <= n; ++i) p[i] = i;
    int total = 0;
    for (auto &edge : edges)
    {
        if (unionSet(edge.u, edge.v))
        {
            mst.push_back(edge);
            total += edge.w;
            if (mst.size() == n - 1) break;
        }
    }
    if (mst.size() != n - 1) return 0; 
    return total;
}
int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    cin >> n >> m;
    edges.clear();
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int total = kruskal();
    if (total == 0) cout << 0 << endl;
    else
    {
        cout << total << endl;
        for (auto e : mst)
        {
            cout << e.u << ' ' << e.v << ' ' << e.w << endl;
        }
    }
    return 0;
}
