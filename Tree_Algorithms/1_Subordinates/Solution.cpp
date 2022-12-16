#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

void solve(vecl& par){

    vecl vret;
    auto s = stack<ll>();
    ll N = par.size();
    vector<vecl> c = vector<vecl>(N);
    vecl visited = vecl(N,0);
    for(int i=1;i<N;i++){
        c[par[i]].push_back(i);
    }
    s.push(0);
    while(!s.empty()){
        bool finished = true;
        for(auto x: c[s.top()]){
            if(!visited[x]){
                visited[x] = 1;
                s.push(x);
                finished = false;
            }
        }
        if(!finished) continue;
        vret.push_back(s.top());
        s.pop();
    }
    vecl subs = vecl(par.size(),0);
    for(auto x: vret){
        for(auto y:c[x]){
            subs[x]+=(subs[y]+1);
        }
    }
    for(auto s:subs){
        cout << s<< " ";
    }
    cout << endl;
}


int main()
{
    int N;
    cin >> N;
    vecl par = vecl(N,0);
    ll k=0;
    for(int i=1;i<N;i++){
        cin >> k;
        par[i]=k-1;
    }
    solve(par);
    return 0;
}
