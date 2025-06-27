#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)

const int N = 101;
int g[N][N], in[N], out[N], n;

bool sc()
{
    for (int s = 0; s < n; ++s)
    {
        vector<bool> v(n);
        stack<int> st;
        st.push(s);
        v[s] = 1;
        int cnt = 1;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (int i = 0; i < n; ++i)
                if (g[u][i] && !v[i])
                {
                    v[i] = 1;
                    st.push(i);
                    cnt++;
                }
        }
        if (cnt != n) return 0;
    }
    return 1;
}

int check()
{
    if (!sc())
    {
        vector<vector<int>> ug(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])   ug[i][j] = ug[j][i] = 1;

        vector<bool> v(n);
        stack<int> st;
        st.push(0);
        v[0] = 1;
        int cnt = 1;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (int i = 0; i < n; ++i)
                if (ug[u][i] && !v[i])
                {
                    v[i] = 1;
                    st.push(i);
                    cnt++;
                }
        }
        if (cnt != n) return 0;
    }

    int st = 0, en = 0;
    for (int i = 0; i < n; ++i)
    {
        if (out[i] - in[i] == 1) st++;
        else if (in[i] - out[i] == 1) en++;
        else if (in[i] != out[i]) return 0;
    }

    if (!st && !en) return 1;
    if (st == 1 && en == 1) return 2;
    return 0;
}

vector<int> find(int u)
{
    vector<int> res;
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int u = st.top();
        bool f = 0;
        for (int i = 0; i < n; ++i)
            if (g[u][i])
            {
                g[u][i] = 0;
                st.push(i);
                f = 1;
                break;
            }
        if (!f)
        {
            res.push_back(u + 1);
            st.pop();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    if (t == 1)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> g[i][j];
                if (g[i][j])
                {
                    out[i]++;
                    in[j]++;
                }
            }
        cout << check() << endl;
    }
    else if (t == 2)
    {
        int u;
        cin >> n >> u;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> g[i][j];
                if (g[i][j])
                {
                    out[i]++;
                    in[j]++;
                }
            }
        auto r = find(u - 1);
        for (size_t i = 0; i < r.size(); ++i)
        {
            if (i) cout << " ";
            cout << r[i];
        }
        cout << endl;
    }

    return 0;
}
