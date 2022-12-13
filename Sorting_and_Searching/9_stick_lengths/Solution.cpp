#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;

void solution(vecl& v){
    sort(v.begin(),v.end());
    ll mid = (v.size()-1)/2;
    ll median = v[mid];
    transform(v.begin(),v.end(),v.begin(),[&](ll a){return llabs(a-median);});
    cout << accumulate(v.begin(),v.end(),0L) << endl;
}



int main(){
    int N;
    cin >> N;
    vecl v = vecl(N,0L);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    solution(v);
    return 0;
}