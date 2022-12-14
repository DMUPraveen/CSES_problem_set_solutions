#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using vecl = vector<ll>;

const ll M = 1000000007;
int main(){

    int N;
    cin >> N;
    vecl dp = vecl(N+1,0);
    dp[0] = 1;
    for(ll i=1;i<=N;i++){
        for(ll k=1;k<=6;k++){
            if(i-k >=0){
                dp[i] = (dp[i] + dp[i-k])%M;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}
