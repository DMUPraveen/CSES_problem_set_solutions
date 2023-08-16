#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;
using mapl = unordered_map<ll, vecl>;

void dfs(mapl &t, int s, vecl &stack, vecl &v)
{
    if (v[s])
    {
        return;
    }
    v[s] = 1;
    for (auto x : t[s])
    {
        dfs(t, x, stack, v);
    }
    stack.push_back(s);
}
void dbgp(vecl &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int solution(mapl &t, vecl ds, int n)
{
    vecl dpused = vecl(n, 0);
    vecl dpfree = vecl(n, 0);
    vecl v = vecl(n, 0);
    ll ans = 0;
    for (auto x : ds)
    {
        for (auto y : t[x])
        {
            if (not v[y])
            {
                continue;
            }
            dpfree[x] += dpused[y];
        }
        for (auto y : t[x])
        {
            if (not v[y])
            {
                continue;
            }
            dpused[x] = max(dpused[x], dpfree[x] - dpused[y] + dpfree[y] + 1);
        }
        v[x] = 1;
        ans = max(dpused[x], dpfree[x]);
    }
    return ans;
}
int solve(mapl &t, int n)
{

    vecl v = vecl(n, 0);
    vecl s = vecl();
    dfs(t, 0, s, v);
    // dbgp(v);
    // dbgp(s);
    return solution(t, s, n);
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
    cout << solve(t, N) << endl;

    return 0;
}
