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
    edge(int x, int y, int w)
    {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int n, m;
vector<edge> E;
int par[MAX], d[MAX];

void bellmanFord()
{
    for (int i = 1; i < 1005; ++i) d[i] = 1e9;
    d[m] = 0;
    par[m] = -1;
    for (int i = 1; i < n; ++i)
    {
        for (edge e : E)
        {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < 1e9)
            {
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    par[v] = u;
                }
            }
        }
    }
}

int main()
{
    boost;
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x != 0) E.pb({i, j, x});
        }
    }
    bellmanFord();
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 1e9)
        {
            cout << "K/c " << m << " -> " << i << " = " << d[i] << ";        ";
            int cur = i;
            while (cur != -1)
            {
                cout << cur;
                if (par[cur] != -1) cout << " <- ";
                cur = par[cur];
            }
            if (i == m) cout << " <- " << m << "\n";
            else cout << "\n";
        }
        else cout << "K/c " << m << " -> " << i << " = INF\n";
    }
    return 0;
}
