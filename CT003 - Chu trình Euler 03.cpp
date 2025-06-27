#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, s;
set<int> g[101];

inline void f1()
{
    cin >> n;
    for (int u = 1; u <= n; ++u)
    {
        string l;
        getline(cin >> ws, l);
        stringstream ss(l);
        string v;
        ss >> v;
        while (ss >> v) g[u].insert(stoi(v));
    }

    int in[n + 1] = {}, out[n + 1] = {};
    for (int u = 1; u <= n; ++u) out[u] = g[u].size();
    for (int u = 1; u <= n; ++u)
        for (auto v : g[u]) ++in[v];

    int c1 = 0, c2 = 0;
    for (int u = 1; u <= n; ++u)
    {
        if (abs(in[u] - out[u]) > 1) ++c1;
        if (abs(in[u] - out[u]) == 1) ++c2;
    }

    if (c1) cout << 0;
    else if (c2 == 2) cout << 2;
    else cout << 1;
}

inline void f2()
{
    cin >> n >> s;
    for (int u = 1; u <= n; ++u)
    {
        string l;
        getline(cin >> ws, l);
        stringstream ss(l);
        string v;
        ss >> v;
        while (ss >> v) g[u].insert(stoi(v));
    }

    stack<int> stk;
    vector<int> path;
    stk.push(s);

    while (!stk.empty())
    {
        int u = stk.top();
        if (!g[u].empty())
        {
            int v = *g[u].begin();
            g[u].erase(v);
            g[v].erase(u);
            stk.push(v);
        }
        else
        {
            stk.pop();
            path.push_back(u);
        }
    }

    reverse(all(path));
    for (int u : path) cout << u << ' ';
}

int main()
{
    boost;
    int t;
    cin >> t;
    (t == 1 ? f1 : f2)();
    return 0;
}
