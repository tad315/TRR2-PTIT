#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, start;
int adj[105][105];
vector<vector<int>> results;
bool visited[105];
vector<int> path;

void backtrack(int u, int count)
{
    if (count == n)
    {
        if (adj[u][start])
        {
            path.push_back(start);
            results.push_back(path);
            path.pop_back();
        }
        return;
    }
    for (int v = 1; v <= n; v++)
    {
        if (!visited[v] && adj[u][v])
        {
            visited[v] = true;
            path.push_back(v);
            backtrack(v, count + 1);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];

    memset(visited, false, sizeof(visited));
    visited[start] = true;
    path.push_back(start);

    backtrack(start, 1);

    cout << results.size() << endl;
    for (auto &cycle : results)
    {
        for (int v : cycle) cout << v << " ";
        cout << endl;
    }
    return 0;
}
