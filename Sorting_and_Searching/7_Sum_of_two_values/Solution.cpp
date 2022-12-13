#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using mapl = map<ll, vecl>;

void answer(ll a, ll b)
{
    cout << a + 1 << " " << b + 1 << endl;
}
void solution(vecl &v, ll x)
{
    mapl m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]].push_back(i);
    }
    for (auto &p : m)
    {
        ll r = x - p.first;
        if (m.find(r) == m.end())
        {
            continue;
        }
        if (r == p.first)
        {
            if (m[p.first].size() > 1)
            {
                answer(m[p.first][0], m[p.first][1]);
                return;
            }
            continue;
        }
        answer(m[p.first][0], m[r][0]);
        return;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vecl v = vecl(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    solution(v, x);

    return 0;
}