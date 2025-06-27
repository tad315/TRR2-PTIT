#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int INF = 10000;
int n, s;
int c[105][105];
bool inTree[105];
vector<tuple<int, int, int>> e;

int prim(int start)
{
    int ans = 0;
    fill(inTree, inTree + n + 1, false);
    e.clear();

    inTree[start] = 1;
    
    for (int i = 1; i < n; ++i)
    {
        int minW = INF, u = -1, v = -1;
        for (int j = 1; j <= n; ++j)
        {
            if (inTree[j])
            {
                for (int k = 1; k <= n; ++k)
                {
                    if (!inTree[k] && c[j][k] < minW)
                    {
                        minW = c[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }
        if (u == -1 || v == -1) return 0;
        inTree[v] = 1;
        e.push_back({u, v, c[u][v]});
        ans += c[u][v];
    }
    return ans;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    int ans = prim(s);
    if (e.size() == n - 1) 
    {
        cout << ans << endl;
        for (auto [u, v, w] : e)
            cout << min(u, v) << ' ' << max(u, v) << ' ' << w << endl;
    }
    else cout << 0 << endl;
    return 0;
}
