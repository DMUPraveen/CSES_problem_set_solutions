#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecl = vector<ll>;


void solution(vecl& v){
    auto pos_map = vecl(v.size()+1,0);
    for(int i=0;i<v.size();i++){
        pos_map[v[i]] = i;
    }
    ll N = v.size();
    ll pre_pos = -1;
    ll passes = 1;
    for(int i=1;i<=N;i++){
        if(pos_map[i] < pre_pos){
            passes +=1;
        }
        pre_pos = pos_map[i];
    }
    cout << passes << endl;
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


