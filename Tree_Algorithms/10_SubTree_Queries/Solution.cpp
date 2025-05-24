#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;
using mapl = unordered_map<ll, vecl>;
using vecvecl = vector<vecl>;

void dfs(vecvecl &t, int s, vecl &stack, vecl &v, vecl &l, vecl &p, ll cl = 0)
{
    if (v[s])
    {
        return;
    }
    v[s] = 1;
    l[s] = cl;
    for (auto x : t[s])
    {

        if (!v[x])
        {
            p[x] = s;
            dfs(t, x, stack, v, l, p, cl + 1);
        }
    }
    stack.push_back(s);
}

void print_answer(vecl &ans)
{
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

struct Fenwick
{
    vecl tree;
    int n = 0;
    vecl *array;
    Fenwick(vecl &arr)
    {
        tree = vecl(arr.size() + 1, 0);
        array = &arr;
        n = arr.size();
        for (int k = 0; k < n; k++)
        {
            add(k, arr[k]);
        }
    }
    void add(int k, ll x)
    {
        k++;
        while (k <= n)
        {
            tree[k] += x;
            k += (-k) & k;
        }
    }
    ll sum_range(int a, int b)
    {
        /*
        open interval a,b

        */
        assert(b >= a);
        return sum(b) - sum(a);
    }
    ll sum(int k)
    {
        /*
        Excluding k
        */
        ll s = 0;
        while (k >= 1)
        {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    void change(int k, ll x)
    {
        ll v = (*array)[k];
        add(k, x - v);
    }
};
// vecl solution(vecvecl &t, ll n, vecpl &paths)
// {
// }

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // ll n, m;
    // cin >> n >> m;
    // vecl parents = vecl(n, -1);
    // vecvecl t = vecvecl(n);
    // for (int i = 1; i < n; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     a--;
    //     b--;
    //     t[a].push_back(b);
    //     t[b].push_back(a);
    // }
    // vecpl paths;
    // for (int i = 0; i < m; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     a--;
    //     b--;
    //     paths.push_back(make_pair(a, b));
    // }
    // vecl answer = solution(t, n, paths);
    // print_answer(answer);
    // cout.flush();
}
