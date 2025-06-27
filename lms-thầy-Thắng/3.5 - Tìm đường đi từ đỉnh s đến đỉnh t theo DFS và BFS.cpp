#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back

int used[10000], pre[10000];
vector<vector<int>> a;
void DFS(int u)
{
    used[u] = 1;
    for (int it : a[u])
    {
        if (!used[it])
        {
            pre[it] = u;
            DFS(it);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = 1;
    while (q.size())
    {
        int i = q.front();
        q.pop();
        for (int it : a[i])
        {
            if (!used[it])
            {
                pre[it] = i;
                used[it] = 1;
                q.push(it);
            }
        }
    }
}

int main()
{
    boost;
    int n, s, t;
    cin >> n >> s >> t;
    a.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x) a[i].pb(j);
        }
    }
    memset(used, 0, sizeof(used));
    memset(pre, 0, sizeof(pre));
    vector<int> path;
    
    DFS(s);

    if (!used[t])
    {
        cout << "no path";
        return 0;
    }
    cout << "DFS path: ";
    for (int v = t; v; v = pre[v]) path.pb(v);
    for (int v : path) cout << v << " ";
    cout << endl;

    memset(used, 0, sizeof(used));
    memset(pre, 0, sizeof(pre));
    path.clear();

    BFS(s);

    cout << "BFS path: ";
    for (int v = t; v; v = pre[v]) path.pb(v);
    for (int v : path) cout << v << " ";
    cout << endl;
}
