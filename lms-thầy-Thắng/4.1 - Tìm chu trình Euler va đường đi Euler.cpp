#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define MAX 1005

set<int> ke[MAX];
int a[MAX][MAX];
int check[MAX];

void dfs(int u)
{
    vector<int> CE;
    stack<int> st;
    st.push(u);
    check[u] = 1;
    while (!st.empty())
    {
        int v = st.top();
        if (ke[v].size())
        {
            int t = *ke[v].begin();
            st.push(t);
            ke[t].erase(v);
            ke[v].erase(t);
        }
        else
        {
            st.pop();
            CE.push_back(v);
        }
    }
    reverse(all(CE));
    for (int x : CE) cout << x << ' ';
}

int main()
{
    boost;
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                ke[i].insert(j);
                ke[j].insert(i);
            }
        }
    }
    dfs(t);
}
