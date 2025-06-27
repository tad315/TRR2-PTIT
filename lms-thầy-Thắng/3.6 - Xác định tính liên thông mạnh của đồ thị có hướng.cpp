#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back


int n, visited[1000007];
vector<vector<int>> a(1000007);

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x) a[i].emplace_back(j);
        }
    }
}
void dfs(int i)
{
    visited[i] = 1;
    for (int it : a[i])
        if (!visited[it]) dfs(it);
}

int solve()
{
    memset(visited, 0, sizeof(visited));
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) return 0;
    for (int i = 2; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        if (!visited[1]) return 0;
    }
    return 1;
}
int main()
{
    boost;
    input();
    if (solve()) cout << "strongly connected";
    else cout << "not strongly connected";
}
