#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int N = 100;
int n, a[N][N];
bool vis[N];

void dfs(int u, int g[N][N]) 
{
    vis[u] = 1;
    for (int v = 0; v < n; ++v)
        if (g[u][v] && !vis[v]) dfs(v, g);
}

bool strong() 
{
    for (int i = 0; i < n; ++i) 
    {
        fill(vis, vis + n, 0);
        dfs(i, a);
        for (int j = 0; j < n; ++j) if (!vis[j]) return false;
    }

    int r[N][N]; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = a[j][i];

    for (int i = 0; i < n; ++i) 
    {
        fill(vis, vis + n, 0);
        dfs(i, r);
        for (int j = 0; j < n; ++j)
            if (!vis[j]) return false;
    }
    return true;
}

bool weak() 
{
    int b[N][N] = {};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] || a[j][i]) b[i][j] = b[j][i] = 1;

    fill(vis, vis + n, 0);
    dfs(0, b);
    for (int i = 0; i < n; ++i) if (!vis[i]) return false;
    return true;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    if (strong()) cout << 1;
    else if (weak()) cout << 2;
    else cout << 0;
    return 0;
}
