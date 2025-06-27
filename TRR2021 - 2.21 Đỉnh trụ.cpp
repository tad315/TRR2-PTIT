#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int N = 100;
int n, a[N][N];
bool vis[N];
int tin[N], low[N], timer;
set<int> ap;    

void dfs(int u, int p) 
{
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v = 0; v < n; ++v) 
    {
        if (a[u][v] == 0 || v == p) continue;

        if (vis[v]) low[u] = min(low[u], tin[v]);
        
        else 
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) ap.insert(u);
            ++children;
        }
    }

    if (p == -1 && children > 1) ap.insert(u);
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    fill(vis, vis + n, false);
    timer = 0;

    for (int i = 0; i < n; ++i)
        if (!vis[i]) dfs(i, -1);

    cout << ap.size() << endl;
    if (!ap.empty()) 
    {
        vector<int> res(ap.begin(), ap.end());
        for (int u : res) cout << u + 1 << " ";
        cout << endl;
    }
    return 0;
}
