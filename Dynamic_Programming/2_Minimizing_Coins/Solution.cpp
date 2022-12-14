#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using vecl = vector<ll>;

int main(){

    int N,X;
    cin >> N >> X;
    vecl v = vecl(X+1,-1);
    vecl c = vecl(N,0);
    v[0] = 0;
    for(ll i=0;i<N;i++){
        cin >> c[i];
    }
    for(ll i=0;i<=X;i++){
        for(auto x:c){
            ll r = i+x;
            if(r <=X && v[i] !=-1){
                v[r] = (v[r] == -1) ? v[i]+1 : min(v[r],v[i]+1);
            }
        }
    }
    cout << v[X] << endl;
    return 0;
}
