#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)

bool isConnected(const vector<vector<int>> &adj, int n)
{
    vector<bool> visited(n, false);
    stack<int> s;
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        if (adj[i].size() > 0)
        {
            start = i;
            break;
        }
    }
    s.push(start);
    visited[start] = true;
    int count = 1;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (int v = 0; v < n; ++v)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                s.push(v);
                count++;
            }
        }
    }
    return count == n;
}

int checkEuler(const vector<vector<int>> &adj, int n)
{
    if (!isConnected(adj, n)) return 0;
    int oddDegree = 0;
    for (int i = 0; i < n; ++i)
    {
        int degree = 0;
        for (int j = 0; j < n; ++j)
        {
            if (adj[i][j] == 1) degree++;
        }
        if (degree % 2 != 0) oddDegree++;
    }
    if (oddDegree == 0) return 1; 
    else if (oddDegree == 2) return 2;
    else return 0; 
}

vector<int> findEulerCycle(vector<vector<int>> adj, int n, int u)
{
    stack<int> path;
    vector<int> cycle;
    path.push(u);
    while (!path.empty())
    {
        int current = path.top();
        bool hasEdge = false;
        for (int v = 0; v < n; ++v)
        {
            if (adj[current][v] == 1)
            {
                adj[current][v] = 0;
                adj[v][current] = 0;
                path.push(v);
                hasEdge = true;
                break;
            }
        }
        if (!hasEdge)
        {
            cycle.push_back(current + 1); 
            path.pop();
        }
    }
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main()
{
    fast;
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    if (t == 1)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> adj[i][j];
            
        int result = checkEuler(adj, n);
        cout << result << endl;
    }
    else if (t == 2)
    {
        int n, u;
        cin >> n >> u;
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> adj[i][j];
        }
        vector<int> cycle = findEulerCycle(adj, n, u - 1); 
        for (size_t i = 0; i < cycle.size(); ++i)
        {
            if (i != 0) cout << " ";
            cout << cycle[i];
        }
        cout << endl;
    }
    return 0;
}
