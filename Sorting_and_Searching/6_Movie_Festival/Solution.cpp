#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecpl = vector<pair<ll,ll>>;


void solution(vecpl& v){
    ll count = 0;
    ll pre_f = -1;
    count = 0 ;
    for(auto x: v){
        if(x.second >= pre_f){
            count ++;
            pre_f = x.first;
        }
    }
    cout << count << endl;
}


int main(){
    ll N = 0;
    cin >> N;
    vecpl v;
    ll a;
    ll b;
    for(ll i=0;i<N;i++){
        cin >> a >> b;
        v.push_back(make_pair(b,a)); 
    }
    sort(v.begin(),v.end());
    solution(v);

    return 0;
}