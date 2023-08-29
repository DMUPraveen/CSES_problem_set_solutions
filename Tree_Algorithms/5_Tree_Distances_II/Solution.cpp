#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;
using mapl = unordered_map<ll, vecl>;

void dfs(mapl &t, int s, vecl &stack, vecl &v, vecl &p)
{
    if (v[s])
    {
        return;
    }
    v[s] = 1;
    for (auto x : t[s])
    {
        if (!v[x])
        {
            p[x] = s;
            dfs(t, x, stack, v, p);
        }
    }
    stack.push_back(s);
}

vecl solve(mapl &t, int n)
{

    vecl s = vecl();
    vecl v = vecl(n, 0);
    vecl p = vecl(n, -1);
    dfs(t, 0, s, v, p);
    vecl sb = vecl(n, 0);
    vecl nb = vecl(n, 0);
    vecl st = vecl(n, 0);
    vecl nt = vecl(n, 0);

    for (auto x : s)
    {
        for (auto c : t[x])
        {
            if (c == p[x])
            {
                continue;
            }
            nb[x] += nb[c] + 1;
            sb[x] += sb[c] + nb[c] + 1;
        }
    }
    reverse(s.begin(), s.end());
    for (auto x : s)
    {
        if (p[x] == -1)
        {
            continue;
        }
        nt[x] = nt[p[x]] + nb[p[x]] - nb[x];
        st[x] = st[p[x]] + sb[p[x]] - sb[x] - nb[x] + nt[x] - 1;
    }
    for (int i = 0; i < st.size(); i++)
    {
        st[i] += sb[i];
    }
    return st;
}
void print_answer(vecl &ans)
{
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    ll N;
    cin >> N;
    ll a, b;
    mapl t;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    vecl ans = solve(t, N);
    print_answer(ans);

    return 0;
}
