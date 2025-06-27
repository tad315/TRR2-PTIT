#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n;
vector<vector<int>> a;

void task1()
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1) cnt++;
        cout << cnt << " ";
    }
    cout << endl;
}

void task2()
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] == 1) ans.emplace_back(i + 1, j + 1);
        }
    }
    cout << n << " " << ans.size() << endl;
    for (auto &x : ans)
        cout << x.first << " " << x.second << endl;
    
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;

    int t;
    cin >> t >> n;

    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    if (t == 1) task1();
    else if (t == 2) task2();
    return 0;
}
