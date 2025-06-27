#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 10005;
int used[MAXN];
vector<vector<int>> a;

void DFS(int u)
{
    used[u] = 1;
    for (int v : a[u])
        if (!used[v]) DFS(v);
    
}

int main()
{
    boost;
    int n, cnt = 0;
    cin >> n;

    a.assign(n + 1, vector<int>()); 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            if (x)
                a[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            cnt++;
            DFS(i);
        }
    }

    cout << cnt << endl;
    return 0;
}
