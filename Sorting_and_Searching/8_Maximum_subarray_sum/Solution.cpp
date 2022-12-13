#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vecl = vector<ll>;



void solution(vecl& v){
    ll best_ending = v[0];

    ll best_overall = v[0];

    for(int i=1;i<v.size();i++){
        ll x = v[i];
        if(best_ending <0){
            best_ending = x;
        }
        else{
            best_ending +=x;
        }
        best_overall = max(best_ending,best_overall);
    }
    cout << best_overall << endl;


}
int main(){
    int N;
    cin >>N;
    vecl v = vecl(N,0);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    solution(v);


    return 0;
}