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

void push_val(vecpl &v1, vecpl &v2, ll n, ll c, ll d)
{
    if (d > v1[n].second)
    {
        auto pre_val = v1[n];
        v1[n].second = d;
        v1[n].first = c;
        v2[n] = pre_val;
        return;
    }

    if (d > v2[n].second)
    {
        v2[n].second = d;
        v2[n].first = c;
        return;
    }
}

vecl solve(mapl &t, int n)
{

    vecl s = vecl();
    vecl v = vecl(n, 0);
    vecl p = vecl(n, -1);
    dfs(t, 0, s, v, p);
    vecl vv = vecl(n, 0);
    vecpl max_down1 = vecpl(n);
    fill(max_down1.begin(), max_down1.end(), make_pair(-1, 0));
    vecpl max_down2 = vecpl(n);
    fill(max_down2.begin(), max_down2.end(), make_pair(-1, 0));
    for (auto x : s)
    {
        for (auto y : t[x])
        {
            if (!vv[y])
            {
                continue;
            }
            ll new_val = max_down1[y].second + 1;
            push_val(max_down1, max_down2, x, y, new_val);
        }

        vv[x] = 1;
    }
    reverse(s.begin(), s.end());
    vecpl answer1 = vecpl(n);
    vecpl answer2 = vecpl(n);
    fill(answer1.begin(), answer1.end(), make_pair(-1, 0));
    fill(answer2.begin(), answer2.end(), make_pair(-1, 0));
    for (auto x : s)
    {
        push_val(answer1, answer2, x, max_down1[x].first, max_down1[x].second);
        push_val(answer1, answer2, x, max_down2[x].first, max_down2[x].second);
        if (p[x] != -1)
        {
            if (answer1[p[x]].first == x)
            {
                push_val(answer1, answer2, x, p[x], answer2[p[x]].second + 1);
            }
            else
            {
                push_val(answer1, answer2, x, p[x], answer1[p[x]].second + 1);
            }
        }
    }
    vecl answer = vecl(n);
    for (int i = 0; i < n; i++)
    {
        answer[i] = answer1[i].second;
    }
    return answer;
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
