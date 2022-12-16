#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;


int main(){
    int N,K;
    cin >> N>>K;
    vecl dp = vecl(K+1,0);
    vecl c = vecl(N,0);
    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(ll k=0;k<N;k++){
        for(ll i=c[k];i<(K+1);i++){
            dp[i] = (dp[i]+dp[i-c[k]])%M;
        }
    }
    cout << dp[K]  << endl;


    return 0;
}