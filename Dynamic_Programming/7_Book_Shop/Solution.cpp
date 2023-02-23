#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;
const ll MAX_PRICE = 100000 + 5;
const ll MAX_BOOKS = 1000 + 5;

ll dp[MAX_PRICE] = {-1};
ll prices[MAX_BOOKS] = {0};
ll pages[MAX_BOOKS] = {0};

int main()
{
    ll N;
    ll x;
    // vecl dp = vecl(MAX_BOOKS, -1);
    cin >> N >> x;
    dp[0] = 0;
    for (ll b = 0; b < N; b++)
    {
        cin >> prices[b];
    }
    for (ll b = 0; b < N; b++)
    {
        cin >> pages[b];
    }
    for (ll b = 0; b < N; b++)
    {
        for (ll i = x; i >= 0; i--)
        {
            ll page = pages[b];
            ll price = prices[b];
            ll pre_price = i - price;
            if (pre_price < 0)
                continue;
            if (dp[pre_price] == -1)
                continue;
            dp[i] = max(dp[i], dp[pre_price] + page);
        }
    }
    cout << *max_element(dp, dp + x + 1) << endl;
}