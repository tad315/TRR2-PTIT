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

const int MAXN = 1005;
int used[MAXN];
vector<vector<int>> adj;
int n;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    used[start] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u])
        {
            if (!used[v])
            {
                used[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    boost;
    cin >> n;
    adj.assign(n + 1, vector<int>()); 

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            if (x) adj[i].pb(j);
        }
    }
    BFS(1);
    return 0;
}
