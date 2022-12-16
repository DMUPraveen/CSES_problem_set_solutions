#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;
using pll = pair<ll, ll>;
using vecpl = vector<pll>;

void solve(vector<vecl>& tre){
    auto s = stack<ll>();
    ll top = 0;
    s.push(0);
    vecl vt = vecl(tre.size(),0);
    vecl gd= vecl(tre.size(),0);
    vt[0] = 1;
    ll count = 0;
    while(!s.empty()){
        ll r = s.top();
        bool finished = true;
        for(auto x: tre[r]){
            if(!vt[x]){
                if(gd[r]!=1){
                    count ++;
                    gd[r] = 1;
                    gd[x] = 1;

                }
                vt[x]=1;
                finished = false;
                s.push(x);
            }
        }
        if(finished){
            s.pop();
        }

    }
    cout << count << endl;
}

int main()
{
    ll N;
    cin >> N;
    vector<vecl> c = vector<vecl>(N);
    ll a,b;
    
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        c[a-1].push_back(b-1);
        c[b-1].push_back(a-1);
    }
    solve(c);

    return 0;
}
