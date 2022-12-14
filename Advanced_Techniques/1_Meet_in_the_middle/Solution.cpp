#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;




using mapl = unordered_map<ll, ll>;

void generate(ll i, ll j, vecl &v,mapl& m)
{
    vecpl vv;
    m[0] = 1;
    for (ll k = i; k < j; k++)
    {
        ll r = 0;
        for (auto x : m)
        {
            r = x.first + v[k];
            vv.push_back(pll(r, x.second));
        }
        for (auto y : vv)
        {
            m[y.first] += y.second;
        }
        vv.clear();
    }
}

void generate2(ll i, ll j, vecl &v,mapl& m)
{

    ll limit = (j - i);
    ll mask_max = 1 << limit;
    for (ll mask = 0; mask < mask_max; mask++)
    {
        ll s = 0;
        ll nmask = mask;
        for (int k = 0; k < limit; k++)
        {
            if (nmask &1)
            {
                s += v[i + k];
            }
            
            nmask = nmask >> 1;
        }
        m[s] += 1;
    }
}

void solution(ll K, vecl &arr)
{
    mapl m1;
    mapl m2;
    ll middle = arr.size() / 2;
    generate2(0, middle, arr,m1);
    ll j = arr.size();
    ll i = middle;
    ll limit = (j - i);
    ll mask_max = 1 << limit;
    ll count =0;
    for (ll mask = 0; mask < mask_max; mask++)
    {
        ll s = 0;
        ll nmask = mask;
        for (int k = 0; k < limit; k++)
        {
            if (nmask &1)
            {
                s += arr[i + k];
            }
            
            nmask = nmask >> 1;
        }
        ll rest = K - s;
        if(m1.count(rest)){
            count += m1[rest];
        }
    }
    cout << count << endl;
}

int main()
{
    ll N, X;
    cin >> N >> X;
    vecl arr = vecl(N, 0);
    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    solution(X, arr);
    return 0;
}
