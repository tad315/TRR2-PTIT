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
vector<pair<int, int>> ke[MAX];
int par[MAX], d[MAX];

void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) d[i] = INT_MAX;
    q.push({0, m});
    d[m] = 0;
    par[m] = -1;

    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();

        if (du != d[u]) continue;
        for (auto x : ke[u])
        {
            int v = x.second;
            int uv = x.first;
            if (d[v] > du + uv)
            {
                d[v] = du + uv;
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

int main()
{
    boost;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x) ke[i].pb({x, j});
        }
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != INT_MAX)
        {
            cout << "K/c " << m << " -> " << i << " = " << d[i] << ";        ";
            int cur = i;
            while (cur != -1)
            {
                cout << cur;
                if (par[cur] != -1) cout << " <- ";
                cur = par[cur];
            }
            if(i == m) cout << " <- " << m << "\n";
            else cout << "\n";
        }
        else
        {
            cout << "K/c " << m << " -> " << i << " = INF\n";
        }
    }
    return 0;
}
