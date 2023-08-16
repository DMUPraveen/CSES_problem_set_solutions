#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;
const ll MAX_PRICE = 100000 + 5;
const ll MAX_BOOKS = 1000 + 5;

const ll MAX_VALUE = 100 + 5;
const ll MAX_SIZE = 100'000 + 5;

ll dp[MAX_SIZE][MAX_VALUE] = {0};
int main()
{
    ll n, m;
    cin >> n >> m;
    ll v = 0;
    cin >> v;
    if (v == 0)
    {
        for (ll x = 1; x <= m; x++)
        {
            dp[0][x] = 1;
        }
    }
    else
    {
        dp[0][v] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
        cin >> v;
        if (v != 0)
        {
            if (v - 1 > 0)
            {
                dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % M;
            }
            if (v + 1 <= m)
            {
                dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % M;
            }
            dp[i][v] = (dp[i][v] + dp[i - 1][v]) % M;
        }
        else
        {
            for (ll x = 1; x <= m; x++)
            {
                if (x - 1 > 0)
                {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % M;
                }
                if (x + 1 <= m)
                {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % M;
                }
                dp[i][x] = (dp[i][x] + dp[i - 1][x]) % M;
            }
        }
    }
    ll sum = 0;
    for (ll v = 1; v <= m; v++)
    {
        sum = (sum + dp[n - 1][v]) % M;
    }
    cout << sum << endl;
}