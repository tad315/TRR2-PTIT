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

struct edge
{
    int x, y, w;
};

int n;
vector<edge> E;
int parent[MAX], sz[MAX];

int Find(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

void Kruskal()
{
    vector<edge> MST;
    int d = 0;
    sort(E.begin(), E.end(), [](edge a, edge b) -> bool
         {
        if(a.w != b.w) return a.w < b.w;
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y; });
    for (edge e : E)
    {
        if (MST.size() == n - 1) break;
        if (Union(e.x, e.y))
        {
            MST.push_back(e);
            d += e.w;
        }
    }
    cout << "dH = " << d << "\n";
    for (edge e : MST) cout << e.x << "   " << e.y << "\n";
}

int main()
{
    cin >> n;
    int z;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            if (z && j > i)
            {
                edge e{i, j, z};
                E.push_back(e);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    Kruskal();
}
