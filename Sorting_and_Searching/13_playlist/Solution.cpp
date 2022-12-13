#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using vecl = vector<ll>;
using setl = unordered_set<ll>;

void solution(vecl& a){
    setl s;
    ll i =0;
    ll j = 0;
    ll longest = 1;
    ll repeated = -1;
    s.insert(a[0]);
    while(true){
        j++;
        if(j >= a.size()) break;
        while(s.count(a[j]) !=0){
            s.erase(a[i]);
            i++;
        }
        s.insert(a[j]);
        ll length = (j-i+1);
        longest = max(length,longest);
    }
    cout << longest << endl;

}

int main()
{

    int N;
    cin >> N ;
    vecl v = vecl(N, 0L);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    solution(v);
    return 0;
}
