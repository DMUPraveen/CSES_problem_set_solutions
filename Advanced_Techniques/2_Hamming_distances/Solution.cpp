#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using vecl = vector<ll>;

void solution(vecl &v){
    ll min_d = LONG_LONG_MAX;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            ll re = v[i]^v[j];
            ll count = __builtin_popcountll(re);
            min_d = min(min_d,count);
        }
    }
    cout << min_d << endl;
}
ll to_bin(string& s){
    ll a = 0;
    for(auto x:s){
        a = a<<1;
        if(x == '1'){
            a+=1;
        }
    }
    return a;
}
int main(){
    int N,K;
    cin >> N >> K;
    vecl v = vecl(N,0);
    string s;
    for(int i=0;i<N;i++){
        cin >>s;
        v[i] = to_bin(s);
        
    }
    solution(v);
    return 0;
}
