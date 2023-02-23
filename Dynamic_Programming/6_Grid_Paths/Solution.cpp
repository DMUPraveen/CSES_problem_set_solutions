#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;
const ll MAX_WIDTH = 1000 + 5;

ll grid[MAX_WIDTH][MAX_WIDTH] = {0};
int main()
{
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < N; j++)
        {
            grid[i][j] = s[j] == '*' ? -1 : 0;
        }
    }
    if (grid[0][0] != -1)
        grid[0][0] = 1;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            // cout << grid[i][j] << " " << i << " " << j << endl;
            if (grid[i][j] == -1)
                continue;
            ll pi = i - 1;
            ll pj = j - 1;
            if (pi >= 0 && grid[pi][j] != -1)
            {
                grid[i][j] = (grid[i][j] + grid[pi][j]) % M;
            }

            if (pj >= 0 && grid[i][pj] != -1)
            {
                // cout << "running pj" << endl;
                grid[i][j] = (grid[i][j] + grid[i][pj]) % M;
            }
        }
    }
    ll ans = grid[N - 1][N - 1];
    if (ans < 0)
        ans = 0;
    ans = ans % M;
    cout << ans << endl;
}