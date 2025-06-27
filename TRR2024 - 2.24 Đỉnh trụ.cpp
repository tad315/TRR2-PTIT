#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int MAX = 100;
int n;
int adj[MAX][MAX], disc[MAX], low[MAX], p[MAX];
bool vis[MAX], isArt[MAX];
int timeCount;

void dfs(int u)
{
    vis[u] = true;
    disc[u] = low[u] = ++timeCount;
    int children = 0;

    for (int v = 0; v < n; ++v)
    {
        if (adj[u][v])
        {
            if (!vis[v])
            {
                children++;
                p[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                if (p[u] == -1 && children > 1) isArt[u] = true;
                
                if (p[u] != -1 && low[v] >= disc[u]) isArt[u] = true;
                
            }
            else if (v != p[u]) low[u] = min(low[u], disc[v]);
        }
    }
}

void findArt()
{
    timeCount = 0;
    fill(vis, vis + n, false);
    fill(p, p + n, -1);
    fill(isArt, isArt + n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i]) dfs(i);
        
    }

    int count = 0;
    vector<int> art;
    for (int i = 0; i < n; ++i)
    {
        if (isArt[i])
        {
            count++;
            art.push_back(i + 1);
        }
    }

    cout << count << endl;
    if (count > 0)
    {
        sort(art.begin(), art.end());
        for (int i = 0; i < art.size(); ++i)
            cout << art[i] << " ";
        cout << endl;
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    fast;

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    findArt();
    return 0;
}
