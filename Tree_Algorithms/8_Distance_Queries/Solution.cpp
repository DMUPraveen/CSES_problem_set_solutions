#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;
using mapl = unordered_map<ll, vecl>;
using vecvecl = vector<vecl>;

void dfs(mapl &t, int s, vecl &stack, vecl &v, vecl &l, vecl &p, ll cl = 0)
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

struct Tree_Climb
{
    vecvecl climb_arr;
    vecl l;
    vecl parents;
    int max_len = 0;
    Tree_Climb(mapl tree, int n)
    {
        parents = vecl(n, 0);
        climb_arr = vecvecl(n);
        max_len = log2(n) + 3;
        for (int i = 0; i < n; i++)
        {
            climb_arr[i] = vecl(max_len, -1);
        }
        vecl ds = vecl();
        vecl v = vecl(n, 0);
        l = vecl(n, 0);
        dfs(tree, 0, ds, v, l, parents);
        reverse(ds.begin(), ds.end());
        for (auto x : ds)
        {
            for (int i = 0; i < max_len; i++)
            {
                if (i == 0)
                {
                    climb_arr[x][i] = parents[x];
                    continue;
                }
                if (climb_arr[x][i - 1] != -1)
                {

                    climb_arr[x][i] = climb_arr[climb_arr[x][i - 1]][i - 1];
                }
                if (climb_arr[x][i] == -1)
                {
                    break;
                }
            }
        }
    }
    ll up(ll x, int k)
    {
        if (k <= 0)
        {
            return x;
        }
        int amount_to_climb = k & (-k);
        int index = log2(amount_to_climb);
        x = climb_arr[x][index];

        if (x == -1)
        {
            return -1;
        }
        ll ans = up(x, k - amount_to_climb);
        return ans;
    }
    ll lca(ll a, ll b)
    {
        if (l[a] > l[b])
        {
            swap(a, b);
        }
        int ld = l[b] - l[a];
        b = up(b, ld);
        while (true)
        {
            if (a == b)
            {
                return a;
            }
            if (parents[a] == parents[b])
            {
                return parents[a];
            }

            int climb_this = max_len - 1;
            for (int i = climb_this; i >= 0; i--)
            {
                if (climb_arr[a][i] != climb_arr[b][i])
                {
                    a = climb_arr[a][i];
                    b = climb_arr[b][i];
                    // climb_this = i + 1;
                }
            }
        }
    }

    ll dis(ll a, ll b)
    {
        ll ca = lca(a, b);
        return l[a] + l[b] - 2 * l[ca];
    }
};

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vecl parents = vecl(n, -1);
    mapl t = mapl();
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    Tree_Climb climber = Tree_Climb(t, n);
    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll ans = climber.dis(a, b);
        cout << ans << "\n";
    }
    cout.flush();
}
