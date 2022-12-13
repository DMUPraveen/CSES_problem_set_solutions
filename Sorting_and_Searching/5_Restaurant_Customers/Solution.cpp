#include <bits/stdc++.h>


using namespace std;
using ll = int64_t;

using vecpl = vector<pair<ll,ll>>;


void solution(vecpl& v){
    ll count = 0;
    ll max_count = -1;
    for(auto x: v){
        if(x.second == 0){
            count++;
        }
        else{
            count--;
        }
        max_count = max(max_count,count);
    }
    cout << max_count << endl;
}

int main(){

    int N=0;
    cin >> N;
    vecpl v = vecpl();
    int s,f = 0;
    for(int i=0;i<N;i++){
        cin >> s >>f;
        v.push_back(make_pair(s,0));
        v.push_back(make_pair(f,1));
    }
    sort(v.begin(),v.end());
    solution(v);
    return 0;
}