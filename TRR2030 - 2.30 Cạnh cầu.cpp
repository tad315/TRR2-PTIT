#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int N = 100;
int n, adj[N][N];
bool vis[N];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v)
        {
            if (adj[u][v] && !vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int countComponents()
{
    fill(vis, vis + n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            bfs(i);
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    vector<pair<int, int>> bridges;
    int initialComponents = countComponents();

    for (int u = 0; u < n; ++u)
    {
        for (int v = u + 1; v < n; ++v)
        {
            if (adj[u][v])
            {
                adj[u][v] = adj[v][u] = 0;
                int newComponents = countComponents();
                if (newComponents > initialComponents)
                    bridges.emplace_back(u + 1, v + 1);
                adj[u][v] = adj[v][u] = 1;
            }
        }
    }

    sort(bridges.begin(), bridges.end());
    freopen("TK.OUT", "w", stdout);
    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges)
        cout << u << ' ' << v << '\n';
    return 0;
}
