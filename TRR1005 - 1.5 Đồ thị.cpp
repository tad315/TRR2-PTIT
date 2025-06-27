#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

int n, m;
vector<pair<int, int>> e;
vector<int> deg;
vector<vector<int>> a;

void task1()
{
    deg.assign(n + 1, 0);
    for (const auto &edge : e)
    {
        deg[edge.first]++;
        deg[edge.second]++;
    }
    for (int i = 1; i <= n; i++) cout << deg[i] << " ";
    cout << endl;
}

void task2()
{
    a.assign(n + 1, vector<int>());
    for (const auto &edge : e)
    {
        a[edge.first].push_back(edge.second);
        a[edge.second].push_back(edge.first);
    }
    for (int i = 1; i <= n; i++) sort(all(a[i]));
    
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].size();
        for (int neighbor : a[i]) cout << " " << neighbor;
        cout << endl;
    }
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;

    int t;
    cin >> t >> n >> m;

    e.resize(m);
    for (int i = 0; i < m; i++) cin >> e[i].first >> e[i].second;
    if (t == 1) task1();    
    else if (t == 2) task2();   
    return 0;
}
