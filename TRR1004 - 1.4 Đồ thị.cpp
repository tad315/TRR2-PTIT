#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> adjMatrix;
vector<int> degree;

void task1()
{
    degree.assign(n + 1, 0);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; ++i) cout << degree[i] << " ";
    cout << endl;
}

void task2()
{
    adjMatrix.assign(n + 1, vector<int>(n + 1, 0));

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << n << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;

    int t;
    cin >> t >> n >> m;

    edges.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].first >> edges[i].second;

    if (t == 1) task1();
    else if (t == 2) task2();
    return 0;
}
