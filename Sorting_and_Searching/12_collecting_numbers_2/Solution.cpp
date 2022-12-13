#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecl = vector<ll>;

ll cal_change(ll less, ll more, ll pre, ll now)
{
    ll re = 0;
    if (less < pre && less > now)
    {
        re += 1;
    }
    if (less > pre && less < now)
    {
        re -= 1;
    }
    if (more > pre && more < now)
    {
        re += 1;
    }
    if (more < pre && more > now)
    {
        re -= 1;
    }
    return re;
}
ll change(ll val, vecl &pos_map, ll pre, ll now)
{
    ll less = pos_map[val - 1];
    ll more = pos_map[val + 1];
    return cal_change(less, more, pre, now);
}
void solution(vecl &v, ll M)
{
    auto pos_map = vecl(v.size() + 2, 0);
    for (int i = 0; i < v.size(); i++)
    {
        pos_map[v[i]] = i;
    }
    pos_map[0] = -1;
    ll N = v.size();
    pos_map[N + 1] = N + 2;
    ll pre_pos = -1;
    ll passes = 1;
    for (int i = 1; i <= N; i++)
    {
        if (pos_map[i] < pre_pos)
        {
            passes += 1;
        }
        pre_pos = pos_map[i];
    }
    int a, b;
    for (ll j = 0; j < M; j++)
    {
        cin >> a >> b;
        a--;
        b--;
        ll va = v[a];
        ll vb = v[b];
        if (llabs(va - vb) == 1)
        {
            if ((va - vb) * (a - b) > 0)
            {
                passes += 1;
            }
            else
            {
                passes -= 1;
            }
        }
        passes += change(v[a], pos_map, a, b);
        passes += change(v[b], pos_map, b, a);
        swap(pos_map[v[a]],pos_map[v[b]]);
        swap(v[a],v[b]);
        cout << passes << "\n";
    }
    cout.flush();
}

int main()
{

    int N, M;
    cin >> N >> M;
    vecl v = vecl(N, 0L);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    solution(v, M);
    return 0;
}
