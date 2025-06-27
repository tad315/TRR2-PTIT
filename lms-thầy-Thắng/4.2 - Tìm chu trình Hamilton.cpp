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

int n;
int a[MAX][MAX];
int X[MAX];
vector<int> check(MAX);

void in()
{
    for (int i = 1; i <= n; i++) cout << X[i] << ' ';
    cout << X[1];
    cout << "\n";
}

void dq(int k)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[X[k - 1]][j] && !check[j])
        {
            X[k] = j;
            check[j] = 1;
            if (k <= n) dq(k + 1);
            else if (X[1] == X[k]) in();
            check[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> n >> t;
    int x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];    
    X[1] = t;
    dq(2);
    return 0;
}
