#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> adj[1000001];
vector<bool> visited;

void DFS(int u)
{

    visited[u] = true;
    cout << u + 1 << " ";

    for (int v : adj[u])
    {
        if (!visited[v]) DFS(v);
    }
}

int main()
{
    boost;
    int n;
    cin >> n;
    adj->resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e;
            cin >> e;
            if (e == 1) adj[i].pb(j);
        }
    }
    DFS(0);
    return 0;
}
