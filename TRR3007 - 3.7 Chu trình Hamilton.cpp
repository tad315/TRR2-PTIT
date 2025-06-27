#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)

int g[101][101], v[101], n, u, cnt;
vector<int> p;
vector<vector<int>> res;

void dfs(int c)
{
    p.push_back(c);
    v[c] = 1;

    if (p.size() == n)
    {
        if (g[c][u])
        {
            p.push_back(u);
            res.push_back(p);
            cnt++;
            p.pop_back();
        }
        p.pop_back();
        v[c] = 0;
        return;
    }

    for (int i = 0; i < n; i++)
        if (g[c][i] && !v[i]) dfs(i);

    p.pop_back();
    v[c] = 0;
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> n >> u;
    u--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    dfs(u);

    if (!cnt) cout << 0;
    else
    {
        for (auto &c : res)
        {
            for (int i = 0; i < c.size(); i++)
                cout << (i ? " " : "") << c[i] + 1;
            cout << endl;
        }
        cout << cnt;
    }

    return 0;
}
