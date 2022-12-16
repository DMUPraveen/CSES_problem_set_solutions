#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

const ll M = 1'000'000'007;


int main(){
    int N;
    cin >> N;
    vecl arr = vecl(N,0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
        // if(arr[i] == 0){
        //     cout << i << endl;
        //     break;
        // }
    }
    vecl dp = vecl(N+1,LONG_LONG_MAX);
    dp[0] = 0;
    for(auto x :arr){
        auto index = upper_bound(dp.begin(),dp.end(),x-1)-1;
        *(index+1) = min(*(index+1),x);
    }
    ll val = (ll)(upper_bound(dp.begin(),dp.end(),LONG_LONG_MAX-1)-dp.begin()-1);
    cout << val << endl;
    
    return 0;
}