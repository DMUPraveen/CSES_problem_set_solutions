#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;

int main()
{
    ll N;
    cin >> N;
    vecl dp = vecl(N + 5, LONG_LONG_MAX);
    dp[N] = 0;
    for (ll i = N; i > 0; i--)
    {
        ll k = i;
        if (dp[i] == LONG_LONG_MAX)
            continue;
        while (k != 0)
        {

            ll r = k % 10;
            dp[i - r] = min(dp[i - r], dp[i] + 1);
            k = k / 10;
        }
    }
    cout << dp[0] << endl;
}