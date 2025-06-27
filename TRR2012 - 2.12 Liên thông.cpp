#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int MAX = 100;
int n;
int adj[MAX][MAX];
bool visited[MAX];
vector<vector<int>> components;

void bfs(int start) 
{
    queue<int> q;
    vector<int> comp;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        comp.push_back(u + 1); 
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] == 1 && !visited[v]) 
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    sort(comp.begin(), comp.end());
    components.push_back(comp);
}

int main() 
{
    fast;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    fill(visited, visited + n, false);

    for (int i = 0; i < n; ++i) 
        if (!visited[i]) bfs(i);

    cout << components.size() << endl;
    for (const auto& comp : components) 
    {
        for (int v : comp) cout << v << " ";
        cout << endl;
    }
    return 0;
}
