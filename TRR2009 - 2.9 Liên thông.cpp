#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> components;

void dfs(int u, vector<int>& comp) 
{
    visited[u] = true;
    comp.push_back(u + 1);
    for (int v = 0; v < n; ++v) 
        if (adj[u][v] && !visited[v]) dfs(v, comp);     
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    adj.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    for (int i = 0; i < n; ++i) 
    {
        if (!visited[i]) 
        {
            vector<int> comp;
            dfs(i, comp);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    cout << components.size() << endl;
    for (const auto& comp : components) 
    {
        for (int v : comp)
            cout << v << " ";
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
