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
vector<pair<int, int>> vt[MAX];
bool visited[MAX];

struct edge
{
    int u, v, w;
};

int st;

void init()
{
    cin >> n >> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x != 0 && i <= j)
            {
                vt[i].pb({j, x});
                vt[j].pb({i, x});
            }
        }
    }
    memset(visited, false, sizeof(visited));
}
void prim(int u)
{
    int d = 0;
    vector<edge> mst;
    visited[u] = true;
    while (mst.size() != n - 1)
    {
        int min_w = 1e9 + 7;
        int x, y;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (auto it : vt[i])
                {
                    if (!visited[it.first])
                    {
                        if (it.second < min_w)
                        {
                            min_w = it.second;
                            y = i;
                            x = it.first;
                        }
                    }
                }
            }
        }
        mst.push_back({x, y, min_w});
        visited[x] = true;
        d += min_w;
    }
    cout << "dH = " << d << "\n";
    for (auto it : mst)
    {
        if (it.u > it.v)
            swap(it.u, it.v);
        cout << it.u << ' ' << it.v << '\n';
    }
}
int main()
{
    boost;
    init();
    prim(st);
    return 0;
}
