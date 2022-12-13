#include<bits/stdc++.h>

using namespace std;
using veci = vector<int64_t>;
using ll = int64_t;





void solution(multiset<ll> hs, veci ts){
    for(auto x:ts){

        auto v = hs.upper_bound(x);
        if(v == hs.begin()){
            cout << -1 << "\n";
        }
        else{
            v--;
            cout << *v << "\n";
            hs.erase(v);
        }


    }

}

int main(){
    int m,n =0;
    cin>> m >> n;
    auto hs = multiset<ll>();
    auto ts = veci(n,0);
    ll val = 0;
    for(int i=0;i<m;i++){
        cin >> val;
        hs.insert(val);
    }
    for(int j=0;j<n;j++){
        cin >> ts[j];
    }
    solution(hs,ts);
    cout.flush();

    return 0;
}