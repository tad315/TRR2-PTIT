#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int INF = 1e9;
int n;
int c[105][105];
int dist[105][105], trace[105][105];

void floyd()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            dist[i][j] = c[i][j];
            if (i != j && c[i][j] < INF) trace[i][j] = i;
            else trace[i][j] = -1;
        }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    trace[i][j] = trace[k][j];
                }
}

vector<int> getPath(int u, int v)
{
    vector<int> path;
    if (trace[u][v] == -1) return path;
    while (v != u)
    {
        path.push_back(v);
        v = trace[u][v];
    }
    path.push_back(u);
    reverse(all(path));
    return path;
}

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] == 10000) c[i][j] = INF;
        }

    floyd();

    int maxLen = -1;
    int best_u = -1, best_v = -1;

    for (int u = 1; u <= n; ++u)
    {
        for (int v = 1; v <= n; ++v)
        {
            if (u == v) continue;
            if (dist[u][v] < INF)
            {
                if (dist[u][v] > maxLen || (dist[u][v] == maxLen && make_pair(u, v) < make_pair(best_u, best_v)))
                {
                    maxLen = dist[u][v];
                    best_u = u;
                    best_v = v;
                }
            }
        }
    }

    if (maxLen == -1) cout << 0 << endl;
    
    else
    {
        cout << best_u << " " << best_v << " " << maxLen << endl;
        vector<int> path = getPath(best_u, best_v);
        for (int v : path) cout << v << " ";
        cout << endl;
    }

    return 0;
}
