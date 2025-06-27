#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, s, t;
int a[505][505];
vector<int> ke[1005];
bool visited[1005];
int parent[1005];

void BFS(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : ke[x])
        {
            if (!visited[y])
            {
                q.push(y);
                parent[y] = x;
                visited[y] = true;
            }
        }
    }
}

void nhap()
{
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int m;
    cin >> m;
    if (m == 1)
    {
        nhap();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[s][i] == 1 && a[i][t] == 1) cnt++;
        cout << cnt;
    }
    else
    {
        nhap();
        BFS(s);
        if (visited[t])
        {
            vector<int> v1;
            while (t != s)
            {
                v1.push_back(t);
                t = parent[t];
            }
            v1.push_back(t);
            reverse(v1.begin(), v1.end());
            for (int x : v1) cout << x << " ";
        }
        else cout << 0;
    }
  return 0;
}
