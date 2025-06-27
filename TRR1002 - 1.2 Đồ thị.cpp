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
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> neighbors;
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1) neighbors.emplace_back(j + 1);

        sort(neighbors.begin(), neighbors.end());
        cout << neighbors.size();
        for (int neighbor : neighbors) cout << " " << neighbor;
        cout << endl;
    }
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
