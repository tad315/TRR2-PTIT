#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int MAX_N = 100; 

int n;
vector<vector<int>> a;
vector<bool> vis;

void DFS_Stack(int start)
{
    stack<int> st;
    st.push(start);
    vis[start] = true;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        cout << u + 1 << " ";

        for (int v = n - 1; v >= 0; --v)
        {
            if (a[u][v] && !vis[v])
            {
                st.push(v);
                vis[v] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    cin >> n;
    a.assign(n, vector<int>(n));
    vis.assign(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    DFS_Stack(0);
    return 0;
}
