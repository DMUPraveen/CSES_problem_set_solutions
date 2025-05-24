#include <bits/stdc++.h>
using namespace std;

long long values[100 + 5] = {0};
long long F[1000000 + 7] = {0};
long long J[1000000 + 7] = {0};
const long long MOD = 1000000000 + 7;
int main()
{
    int n;
    long long max_val = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        max_val = max(max_val, values[i]);
    }
    F[0] = 1;
    F[1] = 2;
    J[0] = 0;
    long long q_k = 4;
    for (int k = 2; k < max_val + 5; k++)
    {
        F[k] = (2 * F[k - 1] + q_k + J[k - 2]) % MOD;
        J[k - 1] = ((4 * J[k - 2]) % MOD + F[k - 1]) % MOD;
        q_k = (q_k * 4) % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        cout << F[values[i]] << "\n";
    }
}