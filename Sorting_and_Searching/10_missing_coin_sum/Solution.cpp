#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecl = vector<ll>;


void solution(vecl& v){
    sort(v.begin(),v.end());
    ll max_sum = 0LL;
    for(auto x: v){
        if(max_sum+1 < x){
            break;
        }

        max_sum = max_sum+x;
    }
    cout << max_sum+1 << endl;
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


