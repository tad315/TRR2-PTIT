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
#define MAX 1005

int a[MAX][MAX];
int check[MAX];
int n;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[curr][v] && !check[v])
            {
                check[v] = 1;
                q.push(v);
            }
        }
    }
}

int tplt()
{
    memset(check, 0, sizeof(check));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            cnt++;
            bfs(i);
        }
    }
    return cnt;
}

int main()
{
    boost;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int originalCC = tplt(); 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                a[i][j] = a[j][i] = 0;

                int newCC = tplt(); 

                if (newCC > originalCC)
                    cout << i << " " << j << endl; 
                
                a[i][j] = a[j][i] = 1;
            }
        }
    }
    return 0;
}
