#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'

int t, n, u, v;
int adj[101][101];
bool visited[101];
vector<int> path;

bool DFS(int cur, int target)
{
    visited[cur] = true;
    path.push_back(cur);
    if (cur == target) return true;
    for (int i = 1; i <= n; i++)
        if (adj[cur][i] && !visited[i])
            if (DFS(i, target)) return true;
    path.pop_back();
    return false;
}

int main()
{
    fast;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];

    if (t == 1)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (adj[u][i] && adj[i][v]) cnt++;
        cout << cnt << endl;
    }
    else
    {
        memset(visited, false, sizeof(visited));
        path.clear();
        if (DFS(u, v))
            for (int x : path) cout << x << " ";
        else cout << 0;
        cout << endl;
    }
    return 0;
}
