#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;
using mapl = unordered_map<ll, vecl>;
using vecvecl = vector<vecl>;

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

struct Tree_Climb
{
    vecvecl climb_arr;
    Tree_Climb(mapl tree, vecl parents, int n)
    {
        climb_arr = vecvecl(n);
        int max_len = log2(n) + 3;
        for (int i = 0; i < n; i++)
        {
            climb_arr[i] = vecl(max_len, -1);
        }
        vecl ds = vecl();
        vecl v = vecl(n, 0);
        vecl p = vecl(n, 0);
        dfs(tree, 0, ds, v, p);
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
    ll query(ll x, int k)
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
        ll ans = query(x, k - amount_to_climb);
        return ans;
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
    ll n, q;
    cin >> n >> q;
    vecl parents = vecl(n, -1);
    mapl children = mapl();
    for (int i = 1; i < n; i++)
    {
        int e = 0;
        cin >> e;
        e--;
        parents[i] = e;
        children[e].push_back(i);
    }
    Tree_Climb climber = Tree_Climb(children, parents, n);
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        ll ans = climber.query(x, k);
        if (ans != -1)
        {
            ans += 1;
        }
        cout << ans << "\n";
    }
    cout.flush();
}
